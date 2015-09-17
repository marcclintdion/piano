    //=======================================================================================                                           
    /*if (keys['J'])                                                                                                                      
    {                                                                                                                                   
             pianoKey_C_Sharp_POSITION[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_POSITION[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_POSITION[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_POSITION[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_POSITION[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_POSITION[2]         -=  .01;                                                                                  
    }*/                                                                                                                                   
    //=======================================================================================                                           
    //=======================================================================================                                           
     if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             pianoKey_C_Sharp_LIGHT_POSITION_01[0]         -=  .11;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_LIGHT_POSITION_01[0]         +=  .11;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_LIGHT_POSITION_01[1]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_LIGHT_POSITION_01[1]         -=  .11;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_LIGHT_POSITION_01[2]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_LIGHT_POSITION_01[2]         -=  .11;                                                                            
    }                                                                                                                                 
    //=======================================================================================                                           
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_ATTENUATION                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_ATTENUATION                  -=  .01;                                                                            
    }                                                                                                                                   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_SHININESS                    +=  1.01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_Sharp_SHININESS                    -=  1.01;                                                                                       
    }                                                                                                                                            
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_SHADER_SETTINGS.cpp");                                                                                     
        outKeys << "  GLfloat     pianoKey_C_Sharp_LIGHT_POSITION_01[] = {" << pianoKey_C_Sharp_LIGHT_POSITION_01[0] << ", "                               
                                                                       << pianoKey_C_Sharp_LIGHT_POSITION_01[1] << ", "                               
                                                                       << pianoKey_C_Sharp_LIGHT_POSITION_01 [2] << ", " << 1.0 << "};\n";          
        outKeys << "  GLfloat     pianoKey_C_Sharp_ATTENUATION         =  " << pianoKey_C_Sharp_ATTENUATION   << ";\n";                                    
        outKeys << "  GLfloat     pianoKey_C_Sharp_SHININESS           =  " << pianoKey_C_Sharp_SHININESS  << ";\n";                                       
    }                                                                                                                                            
