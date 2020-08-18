
void fc3 ( float flattened[outputsiezefc1],
		    float bias[Last_Layer],
			float filter[outputsizefc1][Last_Layer],
			float Fc_output[Last_Layer]

			)
			{

		         for(int i=0;i<Last_Layer;i++)
		     {
		             for(int j=0;j<outputsizefc1;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=Fc_output[i]+bias[i];
		     }
			}
