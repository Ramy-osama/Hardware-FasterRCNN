void fc ( float flattened[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)],
		    float bias[outputsizefc1],
			float filter[outputsizefc1][(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)],
			float Fc_output[outputsizefc1] 
			
			)
			{

				
		         for(int i=0;i<outputsizefc1;i++)
		     { 
		             for(int j=0;j<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);j++)
		             {
		            	 Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];
		             	             }
		             	             Fc_output[i]=Fc_output[i]+bias[i];
		     }
			}
			
