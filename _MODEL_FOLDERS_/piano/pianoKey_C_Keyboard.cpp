    //=======================================================================================                                           
    /*if (keys['J'])                                                                                                                      
    {                                                                                                                                   
             pianoKey_C_POSITION[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_POSITION[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_POSITION[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_POSITION[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_POSITION[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_POSITION[2]         -=  .01;                                                                                  
    }*/                                                                                                                                   
    //=======================================================================================                                           
    //=======================================================================================                                           
                                                                                                                                           
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("_MODEL_FOLDERS_/pianoKey_C/pianoKey_C_SHADER_SETTINGS.cpp");                                                                                     
        
        outKeys << "  GLfloat     pianoKey_Black_LIGHT_POSITION_01[] = {" << pianoKey_Black_LIGHT_POSITION_01[0] << ", "                               
                                                                       << pianoKey_Black_LIGHT_POSITION_01[1] << ", "                               
                                                                       << pianoKey_Black_LIGHT_POSITION_01 [2] << ", " << 1.0 << "};\n";          
        
        outKeys << "  GLfloat     pianoKey_C_ATTENUATION         =  " << pianoKey_C_ATTENUATION   << ";\n";                                    
        outKeys << "  GLfloat     pianoKey_C_SHININESS           =  " << pianoKey_C_SHININESS  << ";\n";                                       
    }                                                                                                                                            
