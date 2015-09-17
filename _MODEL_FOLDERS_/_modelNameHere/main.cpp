
//Author: Damiano Vitulli <info@spacesimulator.net>
////__>>>output texture, normal and vertex arrays added by Marc Clint Dion, Cornwall, Ont, 2007
////__>>>output everything required for rendering with vertex + fragment shading as well as simple planer shadows: M.C.D. -> Dec 2010


#include <windows.h>


#include "glut.h"
#include "load_bmp.h"
#include "load_3ds.h"
#include "object.h"
#include "fstream.h"



int screen_width=640;
int screen_height=480;

double rotation_x=0, rotation_x_increment=0.2;
double rotation_y=0, rotation_y_increment=0.7;
double rotation_z=0, rotation_z_increment=0.0;
 
int filling=1; 

GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_position[]= { 100.0f, 0.0f, -10.0f, 1.0f };

GLfloat mat_ambient[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_diffuse[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat mat_shininess[]= { 1.0f };

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glViewport(0,0,screen_width,screen_height);  

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.0f,100.0f); 
   
	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
    glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);

    glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
    glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);    

	glShadeModel(GL_SMOOTH);                            
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Texture mapping perspective correction (OpenGL... thank you so much!)
    glEnable(GL_TEXTURE_2D);                            // Texture mapping ON
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);         // Polygon rasterization mode (polygon filled)
	glEnable(GL_CULL_FACE);                             // Enable the back face culling
    glEnable(GL_DEPTH_TEST);                            // Enable the depth test (also called z buffer)

	
     ObjLoad ("pianoKey_C_Sharp.3ds","skull.bmp");

      
     
      GLfloat textureMapID = 16;   
      GLuint  vboID        = 16;    
                
    

//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////


system("MKDIR pianoKey_C_Sharp");

ofstream out_Globals("pianoKey_C_Sharp/pianoKey_C_Sharp_Globals.cpp");
         
         
         out_Globals << "GLuint      pianoKey_C_Sharp_SHADER_VERTEX;                                                                                                      "        << "\n";
         out_Globals << "GLuint      pianoKey_C_Sharp_SHADER_FRAGMENT;                                                                                                    "        << "\n";
         out_Globals << "GLuint      pianoKey_C_Sharp_SHADER;                                                                                                             "        << "\n";
         out_Globals << "//--------------------------------------                                                                                              "        << "\n";
         out_Globals << "GLuint      UNIFORM_MODELVIEWPROJ_pianoKey_C_Sharp;                                                                                              "        << "\n";
         out_Globals << "GLuint      UNIFORM_LIGHT_MATRIX_pianoKey_C_Sharp;                                                                                               "        << "\n";
         out_Globals << "//--------------------------------------                                                                                              "        << "\n";
         out_Globals << "GLuint      UNIFORM_LIGHT_POSITION_01_pianoKey_C_Sharp;                                                                                          "        << "\n";
         out_Globals << "GLuint      UNIFORM_SHININESS_pianoKey_C_Sharp;                                                                                                  "        << "\n";         
         out_Globals << "GLuint      UNIFORM_ATTENUATION_pianoKey_C_Sharp;                                                                                                "        << "\n";           
         out_Globals << "GLuint      UNIFORM_TEXTURE_DOT3_pianoKey_C_Sharp;                                                                                               "        << "\n";
         out_Globals << "GLuint      UNIFORM_TEXTURE_pianoKey_C_Sharp;                                                                                                    "        << "\n";
         out_Globals << "//--------------------------------------                                                                                              "        << "\n";

         out_Globals << "GLfloat     pianoKey_C_Sharp_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    "        << "\n";
         out_Globals << "GLfloat     pianoKey_C_Sharp_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   "        << "\n";  
         out_Globals << "GLfloat     pianoKey_C_Sharp_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   "        << "\n";          
         out_Globals << "//-----------------------------------------------------------------                                                                   "        << "\n";         
         out_Globals << "GLfloat     pianoKey_C_Sharp_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  "        << "\n";           
         out_Globals << "GLfloat     pianoKey_C_Sharp_ATTENUATION           =     1.0;                                                                                    "        << "\n";          
         out_Globals << "GLfloat     pianoKey_C_Sharp_SHININESS             =    80.0;                                                                                    "        << "\n";   
         out_Globals << "//-----------------------------------------------------------------                                                                   "        << "\n";
         out_Globals << "GLuint      pianoKey_C_Sharp_VBO;                                                                                                                "        << "\n";             
         out_Globals << "//-----------------------------------------------------------------                                                                   "        << "\n";         
         out_Globals << "GLuint      pianoKey_C_Sharp_NORMALMAP;                                                                                                          "        << "\n";
         out_Globals << "GLuint      pianoKey_C_Sharp_TEXTUREMAP;                                                                                                         "        << "\n";


//====================================================================================================

ofstream out_Init("pianoKey_C_Sharp/pianoKey_C_Sharp_Init.cpp");

         
         out_Init << "      #ifdef __APPLE__                                                                                                                          "        << "\n";
         out_Init << "      #import <OpenGLES/ES2/gl.h>                                                                                                               "        << "\n";
         out_Init << "      #import <OpenGLES/ES2/glext.h>                                                                                                            "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //===============================================================================================                                         "        << "\n";
         out_Init << "      pianoKey_C_Sharp_SHADER = glCreateProgram();                                                                                                         "        << "\n";
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      const GLchar *vertexSource_pianoKey_C_Sharp =                                                                                                        "        << "\n\n";

         out_Init << "      \"    #define highp                                                                                     \\n\"                             "        << "\n\n";

         out_Init << "      \"    uniform highp vec4   light_POSITION_01;                                                           \\n\"                             "        << "\n";
         out_Init << "      \"    uniform         mat4   mvpMatrix;                                                                   \\n\"                           "        << "\n";
         out_Init << "      \"    uniform         mat4   lightMatrix;                                                                 \\n\"                           "        << "\n\n";

         out_Init << "      \"    attribute       vec4   position;                                                                    \\n\"                           "        << "\n";
         out_Init << "      \"    attribute       vec4   normal;                                                                    \\n\"                             "        << "\n";      
         out_Init << "      \"    attribute       vec2   texture;                                                                     \\n\"                           "        << "\n\n";

         out_Init << "      \"    varying highp vec4   normal_PASS;                                                          \\n\"                                    "        << "\n";
         out_Init << "      \"    varying highp vec2   varTexcoord;                                                                 \\n\"                             "        << "\n\n\n";


         out_Init << "      \"    void main()                                                                                         \\n\"                           "        << "\n";
         out_Init << "      \"    {                                                                                                   \\n\"                           "        << "\n";
         out_Init << "      \"        normal_PASS = normalize(lightMatrix * normal);                                           \\n\"                                  "        << "\n\n";
    
         out_Init << "      \"        varTexcoord        = texture;                                                                   \\n\"                           "        << "\n\n";

         out_Init << "      \"        gl_Position        = mvpMatrix * position;                                                      \\n\"                           "        << "\n\n";
         out_Init << "      \"    }\\n\";                                                                                                                             "        << "\n";
         
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      pianoKey_C_Sharp_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   "        << "\n";
         out_Init << "      glShaderSource(pianoKey_C_Sharp_SHADER_VERTEX, 1, &vertexSource_pianoKey_C_Sharp, NULL);                                                                        "        << "\n";
         out_Init << "      glCompileShader(pianoKey_C_Sharp_SHADER_VERTEX);                                                                                                     "        << "\n";
         
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      const GLchar *fragmentSource_pianoKey_C_Sharp =                                                                                                      "        << "\n\n";
  
         out_Init << "      \" #ifdef GL_ES                                                                                                     \\n\"                 "        << "\n";
         out_Init << "      \" #else                                                                                                     \\n\"                        "        << "\n";         
         out_Init << "      \" #define highp                                                                                                  \\n\"                   "        << "\n";
         out_Init << "      \" #endif                                                                                                           \\n\"                 "        << "\n\n";


         out_Init << "      \"    uniform sampler2D       Texture1;                                                                             \\n\"                       "        << "\n";
         out_Init << "      \"    uniform sampler2D       NormalMap;                                                                            \\n\"                       "        << "\n";
         out_Init << "      \"    uniform highp float   shininess;                                                                            \\n\"                       "        << "\n";
         out_Init << "      \"    uniform highp float   attenuation;                                                                          \\n\"                       "        << "\n\n";         

         out_Init << "      \"    varying highp vec4    normal_PASS;                                                                   \\n\"                       "        << "\n";
         out_Init << "      \"    varying highp vec2    varTexcoord;                                                                          \\n\"                       "        << "\n\n";

         out_Init << "      \"     highp  float         NdotL1;                                                                               \\n\"                       "        << "\n";
         out_Init << "      \"     highp  vec3          normal;                                                                               \\n\"                       "        << "\n";
         out_Init << "      \"     highp vec3           NormalTex;                                                                            \\n\"                       "        << "\n\n";

         out_Init << "      \"     void main()                                                                                                  \\n\"                       "        << "\n";
         out_Init << "      \"     {                                                                                                            \\n\"                       "        << "\n";
         out_Init << "      \"         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \\n\"                       "        << "\n";
         out_Init << "      \"         NormalTex             = (NormalTex - 0.5);                                                               \\n\"                       "        << "\n";
         out_Init << "      \"         normal                =  normalize(NormalTex);                                                           \\n\"                       "        << "\n\n";

         out_Init << "      \"         NdotL1                =  dot(normal, vec3(1.0, 1.0, 1.0));                                            \\n\"                       "        << "\n\n";

         out_Init << "      \"         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * 0.2                                  \\n\"                       "        << "\n\n";        

         out_Init << "      \"                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \\n\"                       "        << "\n\n";

         out_Init << "      \"                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \\n\"                       "        << "\n\n";

         out_Init << "      \"    }\\n\";                                                                                                                                   "        << "\n\n";
         out_Init << "      //---------------------------------------------------------------------                                                                         "        << "\n";
         out_Init << "      pianoKey_C_Sharp_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     "        << "\n";
         out_Init << "      glShaderSource(pianoKey_C_Sharp_SHADER_FRAGMENT, 1, &fragmentSource_pianoKey_C_Sharp, NULL);                                                                          "        << "\n";
         out_Init << "      glCompileShader(pianoKey_C_Sharp_SHADER_FRAGMENT);                                                                                                         "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                              "        << "\n";
         out_Init << "      glAttachShader(pianoKey_C_Sharp_SHADER, pianoKey_C_Sharp_SHADER_VERTEX);                                                                                              "        << "\n";
         out_Init << "      glAttachShader(pianoKey_C_Sharp_SHADER, pianoKey_C_Sharp_SHADER_FRAGMENT);                                                                                            "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                              "        << "\n";
         out_Init << "      glBindAttribLocation(pianoKey_C_Sharp_SHADER, 0, \"position\");                                                                                            "        << "\n";
         out_Init << "      glBindAttribLocation(pianoKey_C_Sharp_SHADER, 1, \"normal\");                                                                                           "        << "\n";        
         out_Init << "      glBindAttribLocation(pianoKey_C_Sharp_SHADER, 2, \"texture\");                                                                                             "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                              "        << "\n";
         out_Init << "      glLinkProgram(pianoKey_C_Sharp_SHADER);                                                                                                                    "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                              "        << "\n";
         out_Init << "      #ifdef __APPLE__                                                                                                                                "        << "\n";
         out_Init << "      glDetachShader(pianoKey_C_Sharp_SHADER, pianoKey_C_Sharp_SHADER_VERTEX);                                                                                              "        << "\n";
         out_Init << "      glDetachShader(pianoKey_C_Sharp_SHADER, pianoKey_C_Sharp_SHADER_FRAGMENT);                                                                                            "        << "\n";
         out_Init << "      #endif                                                                                                                                          "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                              "        << "\n";
         out_Init << "      glDeleteShader(pianoKey_C_Sharp_SHADER_VERTEX);                                                                                                            "        << "\n";
         out_Init << "      glDeleteShader(pianoKey_C_Sharp_SHADER_FRAGMENT);                                                                                                          "        << "\n";


         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                "        << "\n";
         out_Init << "      UNIFORM_MODELVIEWPROJ_pianoKey_C_Sharp                   = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"mvpMatrix\");                                              "        << "\n";
         out_Init << "      UNIFORM_LIGHT_MATRIX_pianoKey_C_Sharp                    = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"lightMatrix\");                                            "        << "\n";
         out_Init << "      UNIFORM_LIGHT_POSITION_01_pianoKey_C_Sharp               = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"light_POSITION_01\");                                      "        << "\n"; 
         out_Init << "      UNIFORM_SHININESS_pianoKey_C_Sharp                       = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"shininess\");                                              "        << "\n";         
         out_Init << "      UNIFORM_ATTENUATION_pianoKey_C_Sharp                     = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"attenuation\");                                              "        << "\n";          
         out_Init << "      UNIFORM_TEXTURE_DOT3_pianoKey_C_Sharp                    = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"NormalMap\");                                              "        << "\n";        
         out_Init << "      UNIFORM_TEXTURE_pianoKey_C_Sharp                         = glGetUniformLocation(pianoKey_C_Sharp_SHADER,   \"Texture1\");                                               "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                "        << "\n";


         out_Init << "      //------------------------------------------------------------------------------------------                                              "        << "\n";
         out_Init << "      #ifdef __APPLE__                                                                                                                          "        << "\n";
         out_Init << "      /*filePathName = [[NSBundle mainBundle] pathForResource:@\"pianoKey_C_Sharp_DOT3\" ofType:@\"bmp\"];                                                  "        << "\n";
         out_Init << "      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   "        << "\n";
         out_Init << "      glGenTextures(1, &pianoKey_C_Sharp_NORMALMAP);                                                                                                     "        << "\n";
         out_Init << "      glBindTexture(GL_TEXTURE_2D, pianoKey_C_Sharp_NORMALMAP);                                                                                          "        << "\n";
         out_Init << "      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      "        << "\n";
         out_Init << "      imgDestroyImage(image);                                                                                                                   "        << "\n";
         out_Init << "      //---------------------                                                                                                                   "        << "\n";
         out_Init << "      filePathName = [[NSBundle mainBundle] pathForResource:@\"pianoKey_C_Sharp\" ofType:@\"png\"];                                                       "        << "\n";
         out_Init << "      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   "        << "\n";
         out_Init << "      glGenTextures(1, &pianoKey_C_Sharp_TEXTUREMAP);                                                                                                       "        << "\n";
         out_Init << "      glBindTexture(GL_TEXTURE_2D, pianoKey_C_Sharp_TEXTUREMAP);                                                                                            "        << "\n";
         out_Init << "      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      "        << "\n";
         out_Init << "      imgDestroyImage(image);*/                                                                                                                   "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------                                              "        << "\n";
         out_Init << "      #ifdef WIN32                                                                                                                            "        << "\n";
         out_Init << "      //loadTexture(\"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_DOT3.bmp\",          pianoKey_C_Sharp_NORMALMAP);                                                      "        << "\n";
         out_Init << "      //loadTexture(\"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp.png\",               pianoKey_C_Sharp_TEXTUREMAP);                                                        "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               "        << "\n";
         out_Init << "      #include    \"pianoKey_C_Sharp.cpp\"                                                                                                                "        << "\n";
         out_Init << "      glGenBuffers(1,              &pianoKey_C_Sharp_VBO);                                                                                                "        << "\n";
         out_Init << "      glBindBuffer(GL_ARRAY_BUFFER, pianoKey_C_Sharp_VBO);                                                                                                "        << "\n";
         out_Init << "      glBufferData(GL_ARRAY_BUFFER, sizeof(pianoKey_C_Sharp), pianoKey_C_Sharp, GL_STATIC_DRAW);                                                                    "        << "\n";
         out_Init << "      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         "        << "\n";
         out_Init << "      //=================================================================================================================================       "        << "\n";       
 

//====================================================================================================

ofstream out_Render("pianoKey_C_Sharp/pianoKey_C_Sharp_Render.cpp");

         
         out_Render << "    glUseProgram(pianoKey_C_Sharp_SHADER);                                                                                                                                             "        << "\n";
         out_Render << "    glBindBuffer(GL_ARRAY_BUFFER, pianoKey_C_Sharp_VBO);                                                                                                                               "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             "        << "\n";
         out_Render << "    LoadIdentity(modelView);                                                                                                                                                  "        << "\n";
         out_Render << "    Translate(modelView, pianoKey_C_Sharp_POSITION[0], pianoKey_C_Sharp_POSITION[1], pianoKey_C_Sharp_POSITION[2]);                                                                                      "        << "\n";
         out_Render << "    Rotate(modelView, pianoKey_C_Sharp_ROTATE[0], pianoKey_C_Sharp_ROTATE[1], pianoKey_C_Sharp_ROTATE[2], pianoKey_C_Sharp_ROTATE[3]);//--MODEL                                                                   "        << "\n";
         out_Render << "    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             "        << "\n";
         out_Render << "    LoadIdentity(lightMatrix);                                                                                                                                                "        << "\n";
         out_Render << "    InvertMatrix(lightMatrix, modelView);                                                                                                                                     "        << "\n";
         out_Render << "    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                "        << "\n";
         out_Render << "    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        "        << "\n";
         out_Render << "    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      "        << "\n";       
         out_Render << "    //======================================================================================================                                                                  "        << "\n";         
         out_Render << "    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  "        << "\n";
         out_Render << "    glEnableVertexAttribArray(0);	                                                                                                                                          "        << "\n";
         out_Render << "    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 "        << "\n";
         out_Render << "    glEnableVertexAttribArray(1);                                                                                                                                             "        << "\n";
         out_Render << "    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 "        << "\n";
         out_Render << "    glEnableVertexAttribArray(2);                                                                                                                                             "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          "        << "\n";    
         out_Render << "    glUniform4f(UNIFORM_LIGHT_POSITION_01_pianoKey_C_Sharp, pianoKey_C_Sharp_LIGHT_POSITION_01[0], pianoKey_C_Sharp_LIGHT_POSITION_01[1], pianoKey_C_Sharp_LIGHT_POSITION_01[2], pianoKey_C_Sharp_LIGHT_POSITION_01[3]);   "        << "\n";
         out_Render << "    glUniform1f(UNIFORM_SHININESS_pianoKey_C_Sharp, pianoKey_C_Sharp_SHININESS);                                                                                                                "        << "\n";         
         out_Render << "    glUniform1f(UNIFORM_ATTENUATION_pianoKey_C_Sharp, pianoKey_C_Sharp_ATTENUATION);                                                                                                            "        << "\n";         
         out_Render << "    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_pianoKey_C_Sharp,   1,0,  mvpMatrix);                                                                                                     "        << "\n";
         out_Render << "    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_pianoKey_C_Sharp,    1,0,  lightMatrix);                                                                                                   "        << "\n";
         out_Render << "    //======================================================================================================                                                                  "        << "\n";         
         out_Render << "    /*glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          "        << "\n";
         out_Render << "    glBindTexture(GL_TEXTURE_2D, pianoKey_C_Sharp_NORMALMAP);                                                                                                                          "        << "\n";
         out_Render << "    glUniform1i (UNIFORM_TEXTURE_DOT3_pianoKey_C_Sharp, 1);                                                                                                                            "        << "\n";
         out_Render << "    //---                                                                                                                                                                     "        << "\n";
         out_Render << "    glActiveTexture (GL_TEXTURE0);                                                                                                                                            "        << "\n";
         out_Render << "    glBindTexture(GL_TEXTURE_2D, pianoKey_C_Sharp_TEXTUREMAP);                                                                                                                         "        << "\n";  
         out_Render << "    glUniform1i (UNIFORM_TEXTURE_pianoKey_C_Sharp, 0 );*/                                                                                                                              "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              "        << "\n";
         out_Render << "    glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty * 3 << ");                                                                                                     "        << "\n\n"; 

//====================================================================================================


ofstream out_Keyboard("pianoKey_C_Sharp/pianoKey_C_Sharp_Keyboard.cpp");

         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    /*if (keys['J'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {                                                                                                                                   "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[0]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['L'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[0]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['I'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[1]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['K'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[1]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['O'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[2]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['U'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_POSITION[2]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }*/                                                                                                                                   "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "     if (keys['J'])                                                                                                                   "        << "\n";
         out_Keyboard << "    {                                                                                                                                   "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[0]         -=  .11;                                                                         "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['L'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[0]         +=  .11;                                                                            "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['I'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[1]         +=  .11;                                                                            "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['K'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[1]         -=  .11;                                                                            "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['O'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[2]         +=  .11;                                                                            "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['U'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_LIGHT_POSITION_01[2]         -=  .11;                                                                            "        << "\n";
         out_Keyboard << "    }                                                                                                                                 "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    if (keys['M'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_ATTENUATION                  +=  .01;                                                                            "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['N'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_ATTENUATION                  -=  .01;                                                                            "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['X'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_SHININESS                    +=  1.01;                                                                            "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['Z'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             pianoKey_C_Sharp_SHININESS                    -=  1.01;                                                                                       "        << "\n";
         out_Keyboard << "    }                                                                                                                                            "        << "\n";

         out_Keyboard << "    if (keys[VK_F8]) 			                                                                                                                   "        << "\n";
         out_Keyboard << "	{                                                                                                                                              "        << "\n";
         out_Keyboard << "        ofstream outKeys(\"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_SHADER_SETTINGS.cpp\");                                                                                     "        << "\n";
        
        
         out_Keyboard << "        outKeys << \"  GLfloat     pianoKey_C_Sharp_LIGHT_POSITION_01[] = {\" << pianoKey_C_Sharp_LIGHT_POSITION_01[0] << \", \"                               "        << "\n";
         out_Keyboard << "                                                                       << pianoKey_C_Sharp_LIGHT_POSITION_01[1] << \", \"                               "        << "\n";
         out_Keyboard << "                                                                       << pianoKey_C_Sharp_LIGHT_POSITION_01 [2] << \", \" << 1.0 << \"};\\n\";          "        << "\n";
        
         out_Keyboard << "        outKeys << \"  GLfloat     pianoKey_C_Sharp_ATTENUATION         =  \" << pianoKey_C_Sharp_ATTENUATION   << \";\\n\";                                    "        << "\n";
        
         out_Keyboard << "        outKeys << \"  GLfloat     pianoKey_C_Sharp_SHININESS           =  \" << pianoKey_C_Sharp_SHININESS  << \";\\n\";                                       "        << "\n";
     
         out_Keyboard << "    }                                                                                                                                            "        << "\n";

//====================================================================================================

ofstream out_ShutDown("pianoKey_C_Sharp/pianoKey_C_Sharp_Shutdown.cpp");
//--------------------------------------------------------


         out_ShutDown << "                    /*if(pianoKey_C_Sharp_NORMALMAP != 0)                                                                                        "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteTextures(1, &pianoKey_C_Sharp_NORMALMAP);                                                                  "        << "\n"; 
         out_ShutDown << "                            pianoKey_C_Sharp_NORMALMAP = 0;                                                                                    "        << "\n"; 
         out_ShutDown << "                    }                                                                                                              "        << "\n"; 
         out_ShutDown << "                    if(pianoKey_C_Sharp_TEXTUREMAP  != 0)                                                                                      "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteTextures(1, &pianoKey_C_Sharp_TEXTUREMAP);                                                                 "        << "\n"; 
         out_ShutDown << "                            pianoKey_C_Sharp_TEXTUREMAP  = 0;                                                                                  "        << "\n"; 
         out_ShutDown << "                    }*/                                                                                                             "        << "\n"; 
         out_ShutDown << "                    if(pianoKey_C_Sharp_VBO  != 0)                                                                                             "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteBuffers(1, &pianoKey_C_Sharp_VBO);                                                                         "        << "\n"; 
         out_ShutDown << "                            pianoKey_C_Sharp_VBO  = 0;                                                                                         "        << "\n"; 
         out_ShutDown << "                    }                                                                                                              "        << "\n"; 


//====================================================================================================

ofstream out_LOCATION_STRINGS("pianoKey_C_Sharp/_LOCATION_STRINGS.cpp");
         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Globals.cpp\"                                                                "        <<"\n";                                              
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Init.cpp\"                                                                   "        <<"\n";          
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "//#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Shadow_01.cpp\"                                                              "        <<"\n";         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                  
         out_LOCATION_STRINGS << "//#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Shadow_00.cpp\"                                                              "        <<"\n";           
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                    
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Render.cpp\"                                                                 "        <<"\n";
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                    
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Keyboard.cpp\"                                                               "        <<"\n";         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                  
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/pianoKey_C_Sharp/pianoKey_C_Sharp_Shutdown.cpp\"                                                               "        <<"\n";    
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";       

}    
   

////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////

void display(void)
{
    glDisable(GL_LIGHTING);
   
   
    ofstream outARRAY( "pianoKey_C_Sharp/pianoKey_C_Sharp.cpp" );

    int j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
    glMatrixMode(GL_MODELVIEW); // Modeling transformation
    glLoadIdentity(); // Initialize the model matrix as identity
    glTranslatef(0.0,0.0,-5); // We move the object forward (the model matrix is multiplied by the translation matrix)
    rotation_x = rotation_x + rotation_x_increment;
    rotation_y = rotation_y + rotation_y_increment;
    rotation_z = rotation_z + rotation_z_increment;
    if (rotation_x > 359) rotation_x = 0;
    if (rotation_y > 359) rotation_y = 0;
    if (rotation_z > 359) rotation_z = 0;
    glRotatef(rotation_x,1.0,0.0,0.0); // Rotations of the object (the model matrix is multiplied by the rotation matrices)
    glRotatef(rotation_y,0.0,1.0,0.0);
    glRotatef(rotation_z,0.0,0.0,1.0);
    
    if (object.id_texture!=-1) 
	{
		glBindTexture(GL_TEXTURE_2D, object.id_texture); // We set the active texture 
	    glEnable(GL_TEXTURE_2D); // Texture mapping ON
	}
	else
	    glDisable(GL_TEXTURE_2D); // Texture mapping OFF

outARRAY  << "GLfloat pianoKey_C_Sharp[]   = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";

    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
	for (j=0;j<object.polygons_qty;j++)
	{
		glTexCoord2f( object.mapcoord[ object.polygon[j].a ].u, object.mapcoord[ object.polygon[j].a ].v);
        glNormal3f( object.normal[ object.polygon[j].a ].x, object.normal[ object.polygon[j].a ].y, object.normal[ object.polygon[j].a ].z);
        glVertex3f( object.vertex[ object.polygon[j].a ].x, object.vertex[ object.polygon[j].a ].y, object.vertex[ object.polygon[j].a ].z);
        //-------------------------------------------------------------------------------------------------------------------------------------------
        glTexCoord2f( object.mapcoord[ object.polygon[j].b ].u, object.mapcoord[ object.polygon[j].b ].v);
        glNormal3f( object.normal[ object.polygon[j].b ].x, object.normal[ object.polygon[j].b ].y, object.normal[ object.polygon[j].b ].z);
        glVertex3f( object.vertex[ object.polygon[j].b ].x, object.vertex[ object.polygon[j].b ].y, object.vertex[ object.polygon[j].b ].z);
        //-------------------------------------------------------------------------------------------------------------------------------------------					
        glTexCoord2f( object.mapcoord[ object.polygon[j].c ].u, object.mapcoord[ object.polygon[j].c ].v);
        glNormal3f( object.normal[ object.polygon[j].c ].x, object.normal[ object.polygon[j].c ].y, object.normal[ object.polygon[j].c ].z);
        glVertex3f( object.vertex[ object.polygon[j].c ].x, object.vertex[ object.polygon[j].c ].y, object.vertex[ object.polygon[j].c ].z);
        //==================================================================================================================================
        outARRAY << "" << object.vertex[   object.polygon[j].a ].x << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].a ].y << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].a ].z << ",";    
        //----------------------------------------------------------------------
        outARRAY << "" << object.normal[   object.polygon[j].a ].x << ", ";
        outARRAY <<       object.normal[   object.polygon[j].a ].y << ", ";
        outARRAY <<       object.normal[   object.polygon[j].a ].z <<  ",";    
        //----------------------------------------------------------------------        
        outARRAY << "" << object.mapcoord[ object.polygon[j].a ].u << ", ";
        outARRAY <<       object.mapcoord[ object.polygon[j].a ].v << ",\n";    
	    //======================================================================    
        outARRAY << "" << object.vertex[   object.polygon[j].b ].x << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].b ].y << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].b ].z << ",";	    
        //----------------------------------------------------------------------    
        outARRAY << "" << object.normal[   object.polygon[j].b ].x << ", ";
        outARRAY <<       object.normal[   object.polygon[j].b ].y << ", ";
        outARRAY <<       object.normal[   object.polygon[j].b ].z << ",";    
        //----------------------------------------------------------------------		
        outARRAY << "" << object.mapcoord[ object.polygon[j].b ].u << ", ";
        outARRAY <<       object.mapcoord[ object.polygon[j].b ].v << ",\n";    
	    //======================================================================     
        outARRAY << "" << object.vertex[   object.polygon[j].c ].x << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].c ].y << ", ";
        outARRAY <<       object.vertex[   object.polygon[j].c ].z << ",";    
        //----------------------------------------------------------------------        
        outARRAY << "" << object.normal[   object.polygon[j].c ].x << ", ";
        outARRAY <<       object.normal[   object.polygon[j].c ].y << ", ";
        outARRAY <<       object.normal[   object.polygon[j].c ].z << ",";    
        //----------------------------------------------------------------------    
 	    outARRAY << "" << object.mapcoord[ object.polygon[j].c ].u << ", ";
        outARRAY <<       object.mapcoord[ object.polygon[j].c ].v << ",\n\n";   
    
    
    }
	
	
	
outARRAY << "};\n";
	
	
 glEnd();    
  
   
    
    //glmDraw(couch, GLM_NONE);
    
    
    glFlush(); // This force the execution of OpenGL commands
    glutSwapBuffers(); // In double buffered mode we invert the positions of the visible buffer and the writing buffer
}
void resize (int p_width, int p_height)
{
	if (screen_width==0 && screen_height==0) exit(0);
    screen_width=p_width; // We obtain the new screen width values and store it
    screen_height=p_height; // Height value

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // We clear both the color and the depth buffer so to draw the next frame
    glViewport(0,0,screen_width,screen_height); // Viewport transformation

    glMatrixMode(GL_PROJECTION); // Projection transformation
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.1f,100.0f);
glutPostRedisplay (); // This command redraw the scene (it calls the same routine of glutDisplayFunc)
}

void keyboard(unsigned char p_key, int p_x, int p_y)
{  
    switch (p_key)
    {
        case ' ':
            rotation_x_increment=0;
            rotation_y_increment=0;
            rotation_z_increment=0;
        break;
		case 'r': case 'R':
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 27:
			exit(0);
		break;
    }
}
void keyboard_s (int p_key, int p_x, int py)
{
    switch (p_key)
    {
        case GLUT_KEY_UP:
            rotation_x_increment = rotation_x_increment +0.005;
        break;
        case GLUT_KEY_DOWN:
            rotation_x_increment = rotation_x_increment -0.005;
        break;
        case GLUT_KEY_LEFT:
            rotation_y_increment = rotation_y_increment +0.005;
        break;
        case GLUT_KEY_RIGHT:
            rotation_y_increment = rotation_y_increment -0.005;
        break;
    }
}
/**********************************************************
 *
 * The main routine
 * 
 *********************************************************/

int main(int argc, char **argv)
{
    // We use the GLUT utility to initialize the window, to handle the input and to interact with the windows system
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("www.spacesimulator.net - 3d engine tutorials - To exit press ESC");    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc (resize);
    glutKeyboardFunc (keyboard);
    glutSpecialFunc (keyboard_s);
    init();
    glutMainLoop();

    return(0);    
}
