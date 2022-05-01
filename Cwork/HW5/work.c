#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "work.h"

// Task 1: 编写交并比IOU计算函数
/*
输入：
    rectangle_box A, rectangle_box B:
        float x,y                   矩形框的中心点坐标
        float w,h                   矩形框的宽和高 

输出：交并比计算结果，一个float类型浮点数
*/

float min (float x,float y)
{
    if(x<=y)
    return x;
    else 
    return y;
}

float max(float x, float y)
{
    if(x>= y)
    return x;
    else
    return y;
}

float iou_compute(rectangle_box A, rectangle_box B)
{
    //code here
    float w = min(A.x+A.w/2,B.x+B.w/2) - max(A.x-A.w/2,B.x-B.w/2);//使用了自定义的min与max来支持浮点数
    float h = min(A.y+A.h/2,B.y+B.h/2) - max(A.y-A.h/2,B.y-B.h/2);
    float s1;
    if(w>0 && h>0)//要记得对这些特殊判断
        s1=w*h;
    else
        s1 =0;
    float sA =A.h * A.w;
    float sB = B.h * B.w;
    float s2 = sA + sB - s1;
    return s1/s2;
}
// pay attention to float!
//w,h no 0;
//every time make and ./test


// Task 2: 编写卷积函数(optional)
/*
输入：
    layer_params para:
        input_w, input_h, input_c   输入特征图的宽、高、通道数(w*h*c)
        kernel_size, kernel_n       卷积核尺寸(size*size)、卷积核数量(n)
        stride                      卷积步长
        pad                         补0的数量，上下左右对称补0
    float *input:                   输入特征图数据，平铺的一维数组
    float *weight:                  卷积核的权重数据，平铺的一维数组
    float *output:                  保存计算结果的一维数组
*/
void convolutional_compute(layer_params para, float* input, float* weight, float* output)
{

    //code here
    int i,j,k;
    int c_i,c_j,c_k;
    int pad = para.pad;
    int kernel_size = para.kernel_size;
    int stride = para.stride;
    
    //step1 padding
    float *tmp_pad;
    int size_of_tmp1;
    size_of_tmp1 = (para.input_w + 2*pad) * (para.input_h + 2*pad) * para.input_c;//这是0扩充后的矩阵
    tmp_pad = (float*)malloc(size_of_tmp1*sizeof(float));//为该矩阵开空间

    for (k=0;k<para.input_c;k++)
	for(j=0;j<para.input_h + 2*pad; j++)
	    for(i=0;i<para.input_w + 2*pad; i++)
	    {
		if(i<pad || j<pad || i>= (para.input_w + pad) || j >= (para.input_h + pad))
		    tmp_pad[i + j*(para.input_w + 2*pad) + k * (para.input_w + 2*pad)*(para.input_h + 2*pad)] = 0.0;
		else
		{
		    tmp_pad[i + j*(para.input_w + 2*pad) + k * (para.input_w + 2*pad)*(para.input_h + 2*pad)] = \
                    input[(i-pad) + (j-pad) * para.input_w + k * (para.input_w) * (para.input_h)];
                }//为该矩阵填充值
	    }
	
    //step2 convolution
    int padding_size_w = para.input_w + 2*pad;
    int padding_size_h = para.input_h + 2*pad;
    int padding_size_c = para.input_c;
    
    int conv_size_w = (padding_size_w - kernel_size) / stride + 1;//这里是输出的结果的矩阵大小
    int conv_size_h = (padding_size_h - kernel_size) / stride + 1;
    int conv_size_c = para.kernel_n;//注意这里是输出通道数
    
    float conv_tmp;
    
    for (k=0; k<conv_size_c; k++)
        for(j=0; j<conv_size_h; j++)
            for(i=0; i<conv_size_w; i++)
            {   
                conv_tmp = 0;
                for (c_k=0; c_k<padding_size_c; c_k++)
                    for(c_j=0; c_j<kernel_size; c_j++)
                        for(c_i=0; c_i<kernel_size; c_i++)
                        {
                            conv_tmp += tmp_pad[(i*stride + c_i) + (j*stride*padding_size_w + padding_size_w * c_j) + \
                                        (padding_size_w * padding_size_h * c_k)] * 
                                        weight[c_i + c_j*kernel_size + c_k*kernel_size*kernel_size + k*kernel_size*kernel_size*padding_size_c];
							//对应的卷积运算，以及累加
                            //实际上不加这个tmp_pad应该也可以做，就是这里的下标判断要相对复杂一点                                                                    
                        }
              	output[i + j*conv_size_w + k*conv_size_h*conv_size_w] = conv_tmp;               
            }
    
    free(tmp_pad);//要记得free该空间
  
    return;  
}



// Task 3: 编写最大值池化函数(optional)
/*
输入：
    layer_params para:
        input_w, input_h, input_c   输入特征图的宽、高、通道数(w*h*c)
        kernel_size                 最大值池化的核尺寸(size*size)
        kernel_n                    无意义
        stride                      池化步长
        pad                         在Darknet中无实际意义，详见文档说明
    float *input:                   输入特征图数据，平铺的一维数组
    float *output:                  保存计算结果的一维数组
*/
void maxpool_compute(layer_params para, float* input, float* output)
{
    //code here
    int b,i,j,k,m,n;
    int w_offset = -para.pad/2;
    int h_offset = -para.pad/2;

    int w = (para.input_w + para.pad - para.kernel_size) / para.stride + 1;//这里是输出的w,h,c
    int h = (para.input_h + para.pad - para.kernel_size) / para.stride + 1;
    int c = para.input_c;

    for(b = 0; b < 1; ++b){//感觉这里的b有点像bitch的意思
        for(k = 0; k < c; ++k){
            for(i = 0; i < h; ++i){
                for(j = 0; j < w; ++j){
                    int out_index = j + w*(i + h*(k + c*b));
                    float max = -FLT_MAX;//FLT_MAX是float的最大值
                    int max_i = -1;
                    for(n = 0; n < para.kernel_size; ++n){
                        for(m = 0; m < para.kernel_size; ++m){
                            int cur_h = h_offset + i * para.stride + n;
                            int cur_w = w_offset + j*para.stride + m;
                            int index = cur_w + para.input_w*(cur_h + para.input_h*(k + b*para.input_c));//在输出对应whc时对应的输入的下标
                            int valid = (cur_h >= 0 && cur_h < para.input_h &&
                                         cur_w >= 0 && cur_w < para.input_w);//判断这个时候是否是下标越界
                            float val = (valid != 0) ? input[index] : -FLT_MAX;
                            max_i = (val > max) ? index : max_i;//max_i应该是为了寻找最大值的下标，但是这里实际上用不到
                            max   = (val > max) ? val   : max;
                        }
                    }
                    output[out_index] = max;
                }
            }
        }
    }
    return;
}


// Task 4: 编写上采样函数(optional)
/*
输入：
    layer_params para:
        input_w, input_h, input_c   输入特征图的宽、高、通道数(w*h*c)
        kernel_size                 无意义
        kernel_n                    无意义
        stride                      上采样系数
        pad                         无意义
    float *input:                   输入特征图数据，平铺的一维数组
    float *output:                  保存计算结果的一维数组

    上采样的方式为：原本的一个像素被简单地复制为 stride*stride 个像素
*/
void upsample_compute(layer_params para, float* input, float* output)
{
    //code here
    int out_w = para.input_w * para.stride;
    int out_h = para.input_h * para.stride;
    int out_c = para.input_c;
    int outputs = out_w * out_h * out_c;
    
    int i,j,k;
    for(i=0;i<outputs;i++)
    {
        output[i] = 0;//先全部初始化为0
    }
        for(k = 0; k < para.input_c; ++k)
        {
            for(j = 0; j < para.input_h*para.stride; ++j)
            {
                for(i = 0; i < para.input_w*para.stride; ++i)
                {
                    int in_index = k*para.input_w*para.input_h + (j/para.stride)*para.input_w + i/para.stride;
                    //注意这里的j/para.stride从而有输入和输出的下标关系
                    int out_index = k*para.input_w*para.input_h*para.stride*para.stride + j*para.input_w*para.stride + i;
                    output[out_index] = input[in_index];//是相同的上采样
                }
            }
        }

    return;
}



