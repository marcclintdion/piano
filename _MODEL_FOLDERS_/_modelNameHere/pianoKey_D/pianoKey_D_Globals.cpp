GLuint      pianoKey_D_SHADER_VERTEX;                                                                                                      
GLuint      pianoKey_D_SHADER_FRAGMENT;                                                                                                    
GLuint      pianoKey_D_SHADER;                                                                                                             
//--------------------------------------                                                                                              
GLuint      UNIFORM_MODELVIEWPROJ_pianoKey_D;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_pianoKey_D;                                                                                               
//--------------------------------------                                                                                              
GLuint      UNIFORM_LIGHT_POSITION_01_pianoKey_D;                                                                                          
GLuint      UNIFORM_SHININESS_pianoKey_D;                                                                                                  
GLuint      UNIFORM_ATTENUATION_pianoKey_D;                                                                                                
GLuint      UNIFORM_TEXTURE_DOT3_pianoKey_D;                                                                                               
GLuint      UNIFORM_TEXTURE_pianoKey_D;                                                                                                    
//--------------------------------------                                                                                              
GLfloat     pianoKey_D_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     pianoKey_D_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     pianoKey_D_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                   
GLfloat     pianoKey_D_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     pianoKey_D_ATTENUATION           =     1.0;                                                                                    
GLfloat     pianoKey_D_SHININESS             =    80.0;                                                                                    
//-----------------------------------------------------------------                                                                   
GLuint      pianoKey_D_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                   
GLuint      pianoKey_D_NORMALMAP;                                                                                                          
GLuint      pianoKey_D_TEXTUREMAP;                                                                                                         
