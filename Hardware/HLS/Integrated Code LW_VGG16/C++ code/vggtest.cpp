#include "defines.h"
#include "image1.h"
#include "image2.h"
#include <iostream>
using namespace std; 

void LW_VGG(float image[L1_IMAGE_CHANNELS][L1_UNPADDED][L1_UNPADDED],float Fc_output_3[Last_Layer]);

int main ()
{
		
       float Fc_output_3[Last_Layer]={0};
       LW_VGG(image2,Fc_output_3);
	 
	   //for (int i=0 ; i<Last_Layer ; i++)
		  // cout<<Fc_output_3[i]<<endl;
		   

 return 0;
}