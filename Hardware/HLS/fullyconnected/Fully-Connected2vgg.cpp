void fc2 ( float flattened[outputsiezefc1],
		    float bias[outputsizefc1],
			float filter[outputsizefc1][outputsizefc1],
			float Fc_output[outputsizefc1]

			)
			{

		         for(int i=0;i<outputsizefc1;i++)
		     {
		             for(int j=0;j<outputsizefc1;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=Fc_output[i]+bias[i];
		     }
			}
