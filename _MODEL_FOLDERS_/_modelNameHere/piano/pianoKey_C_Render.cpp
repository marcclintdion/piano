    glUseProgram(piano_SHADER);                                                                                                                                             
    glBindBuffer(GL_ARRAY_BUFFER, piano_VBO);                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, piano_POSITION[0], piano_POSITION[1], piano_POSITION[2]);                                                                                      
    Rotate(modelView, piano_ROTATE[0], piano_ROTATE[1], piano_ROTATE[2], piano_ROTATE[3]);//--MODEL                                                                   
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_piano, piano_LIGHT_POSITION_01[0], piano_LIGHT_POSITION_01[1], piano_LIGHT_POSITION_01[2], piano_LIGHT_POSITION_01[3]);   
    glUniform1f(UNIFORM_SHININESS_piano, piano_SHININESS);                                                                                                                
    glUniform1f(UNIFORM_ATTENUATION_piano, piano_ATTENUATION);                                                                                                            
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_piano,   1,0,  mvpMatrix);                                                                                                     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_piano,    1,0,  lightMatrix);                                                                                                   
    //======================================================================================================                                                                  
    /*glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, piano_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_piano, 1);                                                                                                                            
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, piano_TEXTUREMAP);                                                                                                                         
    glUniform1i (UNIFORM_TEXTURE_piano, 0 );*/                                                                                                                              
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 126);                                                                                                     

