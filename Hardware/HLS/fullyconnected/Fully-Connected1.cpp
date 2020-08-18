void fc1 ( float flattened[Flatened_SIZE],
		    float bias[outputsizefc1],
			float filter[Flatened_SIZE][outputsizefc1],
			float Fc_output[outputsizefc1]

			)
			{

		         for(int i=0;i<outputsizefc1;i++)
		     {
		             for(int j=0;j<Flatened_SIZE;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=Fc_output[i]+bias[i];
		     }
			}
