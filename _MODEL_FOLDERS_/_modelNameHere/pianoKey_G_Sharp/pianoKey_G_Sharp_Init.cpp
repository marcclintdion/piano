      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      pianoKey_G_Sharp_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_pianoKey_G_Sharp =                                                                                                        

      "    #define highp                                                                                     \n"                             

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                             
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec4   normal;                                                                    \n"                             
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   normal_PASS;                                                          \n"                                    
      "    varying highp vec2   varTexcoord;                                                                 \n"                             


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        normal_PASS = normalize(lightMatrix * normal);                                           \n"                                  

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      pianoKey_G_Sharp_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(pianoKey_G_Sharp_SHADER_VERTEX, 1, &vertexSource_pianoKey_G_Sharp, NULL);                                                                        
      glCompileShader(pianoKey_G_Sharp_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_pianoKey_G_Sharp =                                                                                                      

      " #ifdef GL_ES                                                                                                     \n"                 
      " #else                                                                                                     \n"                        
      " #define highp                                                                                                  \n"                   
      " #endif                                                                                                           \n"                 

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       

      "    varying highp vec4    normal_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  float         NdotL1;                                                                               \n"                       
      "     highp  vec3          normal;                                                                               \n"                       
      "     highp vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, vec3(1.0, 1.0, 1.0));                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * 0.2                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      pianoKey_G_Sharp_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(pianoKey_G_Sharp_SHADER_FRAGMENT, 1, &fragmentSource_pianoKey_G_Sharp, NULL);                                                                          
      glCompileShader(pianoKey_G_Sharp_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(pianoKey_G_Sharp_SHADER, pianoKey_G_Sharp_SHADER_VERTEX);                                                                                              
      glAttachShader(pianoKey_G_Sharp_SHADER, pianoKey_G_Sharp_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(pianoKey_G_Sharp_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(pianoKey_G_Sharp_SHADER, 1, "normal");                                                                                           
      glBindAttribLocation(pianoKey_G_Sharp_SHADER, 2, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(pianoKey_G_Sharp_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(pianoKey_G_Sharp_SHADER, pianoKey_G_Sharp_SHADER_VERTEX);                                                                                              
      glDetachShader(pianoKey_G_Sharp_SHADER, pianoKey_G_Sharp_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(pianoKey_G_Sharp_SHADER_VERTEX);                                                                                                            
      glDeleteShader(pianoKey_G_Sharp_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_pianoKey_G_Sharp                   = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_pianoKey_G_Sharp                    = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_pianoKey_G_Sharp               = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_pianoKey_G_Sharp                       = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_pianoKey_G_Sharp                     = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_pianoKey_G_Sharp                    = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_pianoKey_G_Sharp                         = glGetUniformLocation(pianoKey_G_Sharp_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      /*filePathName = [[NSBundle mainBundle] pathForResource:@"pianoKey_G_Sharp_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &pianoKey_G_Sharp_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, pianoKey_G_Sharp_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"pianoKey_G_Sharp" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &pianoKey_G_Sharp_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, pianoKey_G_Sharp_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);*/                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      //loadTexture("_MODEL_FOLDERS_/pianoKey_G_Sharp/pianoKey_G_Sharp_DOT3.bmp",          pianoKey_G_Sharp_NORMALMAP);                                                      
      //loadTexture("_MODEL_FOLDERS_/pianoKey_G_Sharp/pianoKey_G_Sharp.png",               pianoKey_G_Sharp_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "pianoKey_G_Sharp.cpp"                                                                                                                
      glGenBuffers(1,              &pianoKey_G_Sharp_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_G_Sharp_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_G_Sharp), pianoKey_G_Sharp, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
