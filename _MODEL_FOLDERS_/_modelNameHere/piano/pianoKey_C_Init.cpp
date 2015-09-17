      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      piano_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_piano =                                                                                                        

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
      piano_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(piano_SHADER_VERTEX, 1, &vertexSource_piano, NULL);                                                                        
      glCompileShader(piano_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_piano =                                                                                                            

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
      piano_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(piano_SHADER_FRAGMENT, 1, &fragmentSource_piano, NULL);                                                                          
      glCompileShader(piano_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(piano_SHADER, piano_SHADER_VERTEX);                                                                                              
      glAttachShader(piano_SHADER, piano_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(piano_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(piano_SHADER, 1, "normal");                                                                                           
      glBindAttribLocation(piano_SHADER, 2, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(piano_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(piano_SHADER, piano_SHADER_VERTEX);                                                                                              
      glDetachShader(piano_SHADER, piano_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(piano_SHADER_VERTEX);                                                                                                            
      glDeleteShader(piano_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_piano                   = glGetUniformLocation(piano_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_piano                    = glGetUniformLocation(piano_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_piano               = glGetUniformLocation(piano_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_piano                       = glGetUniformLocation(piano_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_piano                     = glGetUniformLocation(piano_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_piano                    = glGetUniformLocation(piano_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_piano                         = glGetUniformLocation(piano_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      /*filePathName = [[NSBundle mainBundle] pathForResource:@"piano_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &piano_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, piano_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"piano" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &piano_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, piano_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);*/                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      //loadTexture("_MODEL_FOLDERS_/piano/piano_DOT3.bmp",          piano_NORMALMAP);                                                      
      //loadTexture("_MODEL_FOLDERS_/piano/piano.png",               piano_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "piano.cpp"                                                                                                                
      glGenBuffers(1,              &piano_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, piano_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(piano), piano, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
