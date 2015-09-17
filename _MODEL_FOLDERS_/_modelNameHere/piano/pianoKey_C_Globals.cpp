GLuint      piano_SHADER_VERTEX;                                                                                                      
GLuint      piano_SHADER_FRAGMENT;                                                                                                    
GLuint      piano_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_piano;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_piano;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_piano;                                                                                          
GLuint      UNIFORM_SHININESS_piano;                                                                                                  
GLuint      UNIFORM_ATTENUATION_piano;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_piano;                                                                                               
GLuint      UNIFORM_TEXTURE_piano;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     piano_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     piano_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     piano_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     piano_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     piano_SHININESS             =    80.0;                                                                                    
GLfloat     piano_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      piano_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      piano_NORMALMAP;                                                                                                          
GLuint      piano_TEXTUREMAP;                                                                                                         
