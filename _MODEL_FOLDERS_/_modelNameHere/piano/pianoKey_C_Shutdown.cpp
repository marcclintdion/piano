                    /*if(piano_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &piano_NORMALMAP);                                                                  
                            piano_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(piano_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &piano_TEXTUREMAP);                                                                 
                            piano_TEXTUREMAP  = 0;                                                                                  
                    }*/                                                                                                             
                    if(piano_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &piano_VBO);                                                                         
                            piano_VBO  = 0;                                                                                         
                    }                                                                                                              
