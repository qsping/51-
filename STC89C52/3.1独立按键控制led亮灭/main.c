#include <REGX52.H>

void main()
{//P2=0xfe;
//P2_0=0;
/*while (1)
	{ 
  	if(P3_1==0 &&P3_0==0)
  		{ 
	      P2_0=0;
		  	     }
    else
     	{
	      P2_0=1; 
		        	}
	}

}	*/
 while(1)
 		{P2=0x00;//1111 1111	
 	      if(P3_1==1) 
		  {	
		  	P2_0=1;
					}
		  else
		  {
		 	P2_0=1;
					}  
					
		   }
}





					 
