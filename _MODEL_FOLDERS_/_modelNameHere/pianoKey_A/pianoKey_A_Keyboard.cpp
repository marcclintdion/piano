    //=======================================================================================                                           
    /*if (keys['J'])                                                                                                                      
    {                                                                                                                                   
             pianoKey_A_POSITION[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_POSITION[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_POSITION[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_POSITION[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_POSITION[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_POSITION[2]         -=  .01;                                                                                  
    }*/                                                                                                                                   
    //=======================================================================================                                           
    //=======================================================================================                                           
     if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             pianoKey_A_LIGHT_POSITION_01[0]         -=  .11;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_LIGHT_POSITION_01[0]         +=  .11;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_LIGHT_POSITION_01[1]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_LIGHT_POSITION_01[1]         -=  .11;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_LIGHT_POSITION_01[2]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_LIGHT_POSITION_01[2]         -=  .11;                                                                            
    }                                                                                                                                 
    //=======================================================================================                                           
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_ATTENUATION                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_ATTENUATION                  -=  .01;                                                                            
    }                                                                                                                                   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_SHININESS                    +=  1.01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_A_SHININESS                    -=  1.01;                                                                                       
    }                                                                                                                                            
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("_MODEL_FOLDERS_/pianoKey_A/pianoKey_A_SHADER_SETTINGS.cpp");                                                                                     
        outKeys << "  GLfloat     pianoKey_A_LIGHT_POSITION_01[] = {" << pianoKey_A_LIGHT_POSITION_01[0] << ", "                               
                                                                       << pianoKey_A_LIGHT_POSITION_01[1] << ", "                               
                                                                       << pianoKey_A_LIGHT_POSITION_01 [2] << ", " << 1.0 << "};\n";          
        outKeys << "  GLfloat     pianoKey_A_ATTENUATION         =  " << pianoKey_A_ATTENUATION   << ";\n";                                    
        outKeys << "  GLfloat     pianoKey_A_SHININESS           =  " << pianoKey_A_SHININESS  << ";\n";                                       
    }                                                                                                                                            
