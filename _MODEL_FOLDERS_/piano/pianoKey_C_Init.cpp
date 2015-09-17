      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      pianoKey_C_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_pianoKey_C =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec3   normal;                                                                      \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp   vec4   normal_PASS;                                                                 \n"                           
      "    varying highp   vec2   varTexcoord;                                                                 \n"                           

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        normal_PASS = normalize(lightMatrix * vec4(normal, 1.0));                                       \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      pianoKey_C_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(pianoKey_C_SHADER_VERTEX, 1, &vertexSource_pianoKey_C, NULL);                                                                        
      glCompileShader(pianoKey_C_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_pianoKey_C =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"                       

      "    uniform highp float     shininess;                                                                                                    \n"                       
      "    uniform highp float     attenuation;                                                                                                  \n"                       
      "    uniform highp vec4      light_POSITION_01;                                                                                            \n"  
      "    varying highp vec4      normal_PASS;                                                                                                  \n"                       

      "     highp  float           NdotL1;                                                                                                       \n"                       
      "     highp  vec3            normal;                                                                                                       \n"                       

      "     void main()                                                                                                                          \n"                       
      "     {                                                                                                                                    \n"                       
      "         normal                =  normalize(normal_PASS.xyz);                                                                             \n" 
      
      "         NdotL1                =  dot(normal, normalize(light_POSITION_01.xyz));                                                                     \n"                       

      "         gl_FragColor          =  vec4(1.0, 1.0, 1.0, 1.0) * NdotL1 * NdotL1 * attenuation + vec4(1.0, 1.0, 0.9, 1.0) * pow(NdotL1, shininess)*0.0;                  \n"                       

//      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1 * NdotL1 * attenuation                     \n"                       

//      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(0.0, 1.0, .1, 1.0);          \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      pianoKey_C_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(pianoKey_C_SHADER_FRAGMENT, 1, &fragmentSource_pianoKey_C, NULL);                                                                          
      glCompileShader(pianoKey_C_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(pianoKey_C_SHADER, pianoKey_C_SHADER_VERTEX);                                                                                              
      glAttachShader(pianoKey_C_SHADER, pianoKey_C_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(pianoKey_C_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(pianoKey_C_SHADER, 1, "normal");                                                                                           
      glBindAttribLocation(pianoKey_C_SHADER, 2, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(pianoKey_C_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(pianoKey_C_SHADER, pianoKey_C_SHADER_VERTEX);                                                                                              
      glDetachShader(pianoKey_C_SHADER, pianoKey_C_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(pianoKey_C_SHADER_VERTEX);                                                                                                            
      glDeleteShader(pianoKey_C_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_pianoKey_C                   = glGetUniformLocation(pianoKey_C_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_pianoKey_C                    = glGetUniformLocation(pianoKey_C_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_pianoKey_C               = glGetUniformLocation(pianoKey_C_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_pianoKey_C                       = glGetUniformLocation(pianoKey_C_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_pianoKey_C                     = glGetUniformLocation(pianoKey_C_SHADER,   "attenuation");                                              
      //################################################################################################################################################################            
      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      pianoKey_Black_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_pianoKey_Black =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec3   normal;                                                                      \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp   vec4   normal_PASS;                                                                 \n"                           
      "    varying highp   vec2   varTexcoord;                                                                 \n"                           

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        normal_PASS = normalize(lightMatrix * vec4(normal, 1.0));                                       \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      pianoKey_Black_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(pianoKey_Black_SHADER_VERTEX, 1, &vertexSource_pianoKey_Black, NULL);                                                                        
      glCompileShader(pianoKey_Black_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_pianoKey_Black =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"                       

      "    uniform highp float     shininess;                                                                                                    \n"                       
      "    uniform highp float     attenuation;                                                                                                  \n"                       
      "    uniform highp vec4      light_POSITION_01;                                                                                            \n"  
      "    varying highp vec4      normal_PASS;                                                                                                  \n"                       

      "     highp  float           NdotL1;                                                                                                       \n"                       
      "     highp  vec3            normal;                                                                                                       \n"                       

      "     void main()                                                                                                                          \n"                       
      "     {                                                                                                                                    \n"                       
      "         normal                =  normalize(normal_PASS.xyz);                                                                             \n" 
      
      "         NdotL1                =  dot(normal, normalize(light_POSITION_01.xyz));                                                                     \n"                       

      "         gl_FragColor          =  vec4(0.0, 0.0, 0.0, 1.0) * NdotL1 * NdotL1 * attenuation + vec4(1.0, 1.0, 0.9, 1.0) * pow(NdotL1, shininess);                  \n"                       

//      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1 * NdotL1 * attenuation                     \n"                       

//      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(0.0, 1.0, .1, 1.0);          \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      pianoKey_Black_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(pianoKey_Black_SHADER_FRAGMENT, 1, &fragmentSource_pianoKey_Black, NULL);                                                                          
      glCompileShader(pianoKey_Black_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(pianoKey_Black_SHADER, pianoKey_Black_SHADER_VERTEX);                                                                                              
      glAttachShader(pianoKey_Black_SHADER, pianoKey_Black_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(pianoKey_Black_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(pianoKey_Black_SHADER, 1, "normal");                                                                                           
      glBindAttribLocation(pianoKey_Black_SHADER, 2, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(pianoKey_Black_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(pianoKey_Black_SHADER, pianoKey_Black_SHADER_VERTEX);                                                                                              
      glDetachShader(pianoKey_Black_SHADER, pianoKey_Black_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(pianoKey_Black_SHADER_VERTEX);                                                                                                            
      glDeleteShader(pianoKey_Black_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_pianoKey_Black                   = glGetUniformLocation(pianoKey_Black_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_pianoKey_Black                    = glGetUniformLocation(pianoKey_Black_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_pianoKey_Black               = glGetUniformLocation(pianoKey_Black_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_pianoKey_Black                       = glGetUniformLocation(pianoKey_Black_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_pianoKey_Black                     = glGetUniformLocation(pianoKey_Black_SHADER,   "attenuation");                                              
      //################################################################################################################################################################  
           
      //=================================================================================================================================      
      #include    "pianoKey_A.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_A_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_A_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_A), pianoKey_A, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================      
      #include    "pianoKey_A_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_A_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_A_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_A_Sharp), pianoKey_A_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);           
      //=================================================================================================================================        
      #include    "pianoKey_B.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_B_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_B_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_B), pianoKey_B, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
      #include    "pianoKey_C.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_C_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_C_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_C), pianoKey_C, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
      #include    "pianoKey_C_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_C_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_C_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_C_Sharp), pianoKey_C_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================      
      #include    "pianoKey_D.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_D_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_D_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_D), pianoKey_D, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================      
      #include    "pianoKey_D_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_D_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_D_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_D_Sharp), pianoKey_D_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);         
      //================================================================================================================================= 
      #include    "pianoKey_E.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_E_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_E_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_E), pianoKey_E, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //================================================================================================================================= 
      #include    "pianoKey_F.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_F_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_F_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_F), pianoKey_F, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //================================================================================================================================= 
      #include    "pianoKey_F_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_F_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_F_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_F_Sharp), pianoKey_F_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
      #include    "pianoKey_G.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_G_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_G_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_G), pianoKey_G, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //================================================================================================================================= 
      #include    "pianoKey_G_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_G_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_G_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_G_Sharp), pianoKey_G_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //================================================================================================================================= 


















