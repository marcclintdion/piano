
//####################################################################################################################


#ifdef WIN32
        #define glGenerateMipmap       glGenerateMipmapEXT        
        #define glGenFramebuffers      glGenFramebuffersEXT    
        #define glBindFramebuffer      glBindFramebufferEXT          
        #define glFramebufferTexture2D glFramebufferTexture2DEXT            
         
        #define STRICT
        #define WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

        #include <GL/gl.h>

        HDC	       hDC        = NULL;
        HGLRC      hRC        = NULL;
        HWND       hWnd       = NULL;
        HINSTANCE  hInstance  = NULL;
        //-------------------------------
        int        WINAPI       WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
        LRESULT    CALLBACK     WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

        
        //-------------------------------
        void       ProcessKeyboard();
        int        LoadTexture(char *texture_name, GLuint *texture);
        //-------------------------------
        bool keys[256], keypressed[256];



        #include "headerFiles/glext.h" 
        #include "headerFiles/glext_Init_A.cpp" 
        
        #include "headerFiles/VSync.h"   
        
        #include "headerFiles/WGL_ARB_multisample.h"
     
         
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
    
        #include "headerFiles/arb_multisample.h"
        bool domulti = true;
        bool doangle = true;    
    
#endif


//####################################################################################################################


#include <math.h>
  

//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################


//-------------------------------------------------------------------------------------------------------------------- 

const       int TEXTURE_WIDTH  = 1024;
const       int TEXTURE_HEIGHT = 1024;
//------------------------------------
GLuint      depth;

GLuint      fboId_2D; 
//-----------------------
GLuint      shadowMap_2D;

//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef WIN32
               GLfloat viewWidth    = 960;
               GLfloat viewHeight   = 640;
               #include "cpp/WGL_ARB_multisample.cpp"  
        #endif
        #ifdef __APPLE__
               GLfloat viewWidth;
               GLfloat viewHeight;
               GLuint  viewFramebuffer;        
 
        #endif        
        //-------------------------------------------------------------------------------

        GLfloat eyePosition[]   = {  0.0, 2.98, 1.381};
               
        GLfloat look_LEFT_RIGHT =    0.0;
        GLfloat look_UP_DOWN    =   90.0;   


//#########################################################################################################|_FREE_IMAGE

void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif        
        
        glGenerateMipmap(GL_TEXTURE_2D);
}

//===============================================================================================================================                                                   

GLfloat     modelView[16];
GLfloat     projection[16];
GLfloat     mvpMatrix[16];
GLfloat     mvpMatrixInverse[16];
GLfloat     lightMatrix[16];  
GLfloat     moveSetMatrix[16]; 
GLfloat     textureMatrix[16];
GLfloat     ProjectionShadow[16];
GLfloat     LightModelViewMatrix[16];


GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================
                               

//######################################################################################################################
                                GLfloat       globalLinearAttenuation                                   =    0.09;
                                GLfloat       offset[]                                                  =  {20.04, 4.58902, 4.18, 1};
                                GLfloat       moveSet[]                                                 =  { 0.0, 0.0, 0.0}; 
                                //---------------------------------------------------- 
                                #include    "_SHADERS/SHADOWS/shadows_24B_GLOBALS.cpp"                              
                                //----------------------------------------------------
                           
                                //====================================================================================                                          
                                GLfloat     pianoKey_C_POSITION[]              =  {  0.0, 0.0, -0.395, 1.0};                                                                    
                                //-----------------------------------------------------------------------
                                GLfloat     pianoKey_A_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0}; 
                                GLfloat     pianoKey_A_Sharp_ROTATE[]          =  {  1.0, 0.0,  0.0, 0.0}; 
                                GLfloat     pianoKey_B_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};                                                                   
                                GLfloat     pianoKey_C_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_C_Sharp_ROTATE[]          =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_D_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_D_Sharp_ROTATE[]          =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_E_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_F_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_F_Sharp_ROTATE[]          =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_G_ROTATE[]                =  {  1.0, 0.0,  0.0, 0.0};
                                GLfloat     pianoKey_G_Sharp_ROTATE[]          =  {  1.0, 0.0,  0.0, 0.0};
                                //----------------------------------------------------------------------------
                                GLfloat     pianoKey_C_SCALE[]                 = {  1.0, 1.0,  1.0, 1.0};                                                                   
                                //----------------------------------------------------------------------------                                                                       
                                GLfloat     pianoKey_C_LIGHT_POSITION_01[]     = { 0.0, 2.313483, -5.27193, 1};
                                GLfloat     pianoKey_C_ATTENUATION             =    1.0;
                                GLfloat     pianoKey_C_SHININESS               =  113.33;                               
                                //----------------------------------------------------------------------------                                                                       
                                GLfloat     pianoKey_Black_LIGHT_POSITION_01[] = { 0.0, 1.974385, -5.094196, 1};
                                GLfloat     pianoKey_Black_ATTENUATION         =    1.0;
                                GLfloat     pianoKey_Black_SHININESS           =  50.0;                                 
                                
                                #include "_MODEL_FOLDERS_/piano/pianoKey_C_Globals.cpp"                                                                
                                //====================================================================================                                          
                                bool C_keyIsPressed = false;



//======================================================================================================================================================================================



          #ifdef WIN32
             #include "cpp/winInit.cpp"
          #endif  
          
          
          
          
          
//------------------------------------------------------------------------------------------------------------------------                 
  

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

//====================================
//#import <AVFoundation/AVFoundation.h>
//-------------------
//AVAudioPlayer *laser;
//-------------------

//====================================
#ifdef __APPLE__
#include <AudioToolbox/AudioToolbox.h>
SystemSoundID C2;
SystemSoundID D2;
SystemSoundID E2;
SystemSoundID F2;
SystemSoundID G2;
SystemSoundID A2;
SystemSoundID B2;

#endif
//====================================





void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__
{
        
#ifdef __APPLE__
        //====================================================================================================================            
        //NSString *C2 = [[NSBundle mainBundle]  pathForResource:@"funkLoop" ofType:@"mp3"];
        //----------------------------------------------------------------------------------
        NSURL *C2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"C2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)C2_URL, &C2);
        //AudioServicesPlaySystemSound(C2);
        //====================================================================================================================            
        NSURL *D2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"D2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)D2_URL, &D2);
        //AudioServicesPlaySystemSound(D2);
        //====================================================================================================================   
        NSURL *E2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"E2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)E2_URL, &E2);
        //AudioServicesPlaySystemSound(E2);
        //====================================================================================================================           
        NSURL *F2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"F2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)F2_URL, &F2);
        //AudioServicesPlaySystemSound(F2);
        //====================================================================================================================           
        NSURL *G2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"G2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)G2_URL, &G2);
        //AudioServicesPlaySystemSound(G2);
        //====================================================================================================================            
        NSURL *A2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"A2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)A2_URL, &A2);
        //AudioServicesPlaySystemSound(A2);
        //====================================================================================================================           
        NSURL *B2_URL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"B2" ofType:@"mp3"]];
        AudioServicesCreateSystemSoundID((CFURLRef)B2_URL, &B2);
        //AudioServicesPlaySystemSound(B2);
        //====================================================================================================================         
        
        
        
        //====================================================================================================================            
        //NSURL *url = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"funkLoop" ofType:@"mp3"]];
        //funkLoop = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:nil];
	//funkLoop.numberOfLoops = -1;
	//funkLoop.volume = 1.0;
        //[funkLoop play];  
        //====================================================================================================================           
        //NSURL *url2 = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"C2" ofType:@"mp3"]];
        //laser = [[AVAudioPlayer alloc] initWithContentsOfURL:url2 error:nil];
	//laser.numberOfLoops = 0;
	//laser.volume = 1.0;
         
        //====================================================================================================================           
#endif       


        //==========================================================================
        #ifdef WIN32    
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp" 
            //-------------------------------------
            SetVSyncState(true);        
        #endif
        
//=========================================================================================================================================        
        glGenTextures(1, &shadowMap_2D);
        glBindTexture(GL_TEXTURE_2D, shadowMap_2D);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);   
        //--------------------------------------------------------------------------------------------------------------------
        glGenFramebuffers(1, &fboId_2D);
        glBindFramebuffer(GL_FRAMEBUFFER, fboId_2D);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, shadowMap_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //====================================================================================================================                                         
        #include "_SHADERS/SHADOWS/shadows_24B_INIT.cpp"                            
        //====================================================================================    
        #include "_MODEL_FOLDERS_/piano/pianoKey_C_Init.cpp"                                                                
        //====================================================================================                                          
                                    
       
        
//=================================================================================================================== 


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);  


//=====================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


void RenderGL(void)
{
        
        //---------------------------------------------------------------        
        if(C_keyIsPressed == true)
        {
                
        }

        
        
        //---------------------------------------------------------------
        
        
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //=============================================================================================================================  
        
        glBindFramebuffer(GL_FRAMEBUFFER, fboId_2D);//-----------------------F.B.O.     
        //----------------------------------------------------------------
        //glColor4f(color is changed using fragment program)
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear (GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
        //----------------------------------------------------------------
        
      
        //-----------------------------------------------------------------------------------------------------------------------------                                
        
        
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        
        
        PerspectiveMatrix(ProjectionShadow, 45, 1.0, 0.001, 10000.0);
        
        
        Rotate(ProjectionShadow, 0.0, 1.0, 0.0, 20.0);
        Rotate(ProjectionShadow, 1.0, 0.0, 0.0, 45.0);
        
        
        glUseProgram(SHADER_shadow);//---------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  
        
        //############################################################################################################################################################|__SHADOW_01
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===================================================== 
        
//        #include "_MODEL_FOLDERS_/piano/pianoKey_C_Shadow_00.cpp"                                                              
        //====================================================================================  
        
        //============================================================================================================================================================|__LAYER__02       
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================                     
        
        
        //############################################################################################################################################################|__SHADOW_02
        
        
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===========================================================                       

        
        //============================================================================================================================================================|__LAYER__02     
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================
        
        
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
        LoadIdentity(textureMatrix);
        AssignMatrix(textureMatrix, ProjectionShadow); 
        //===========================================================
        glEnable(GL_DEPTH_TEST);                                 
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 	                       
	glBindFramebuffer(GL_FRAMEBUFFER, 0);	                       

        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	 

//##################################################################################################################################################################################################        
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################          
        
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //========================================================================================================================================================        
        #ifdef __APPLE__    
            glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        #endif    
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================

        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //========================================================================================================================================================= 
        glViewport(0, 0, viewWidth, viewHeight);
        PerspectiveMatrix(projection, 45,(float)viewWidth / (float)viewHeight, 0.1, 10000);
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];
        #endif
        //=========================================================================================================================================================

        #ifdef WIN32
                projection[12] = eyePosition[0];
                projection[13] = eyePosition[1];
                projection[15] = eyePosition[2];                 
        #endif
                 
                Rotate(projection, 1.0, 0.0, 0.0, look_UP_DOWN);
                Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);        
        
//#################################################################################################################################################################        
        
        //moveSet[0] -= 0.01;
        //moveSet[1] -= 0.004;        
        
        
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/piano/pianoKey_A_Render.cpp"                                                                 
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/piano/pianoKey_A_Sharp_Render.cpp"                                                                 
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/piano/pianoKey_B_Render.cpp"                                                                 
        //====================================================================================             
        #include "_MODEL_FOLDERS_/piano/pianoKey_C_Render.cpp"                                                                 
        //====================================================================================             
        #include "_MODEL_FOLDERS_/piano/pianoKey_C_Sharp_Render.cpp"                                                                 
        //====================================================================================                                      
        #include "_MODEL_FOLDERS_/piano/pianoKey_D_Render.cpp"                                                                 
        //====================================================================================                                      
        #include "_MODEL_FOLDERS_/piano/pianoKey_D_Sharp_Render.cpp"         
        //====================================================================================        
        #include "_MODEL_FOLDERS_/piano/pianoKey_E_Render.cpp"                                                                 
        //====================================================================================            
        #include "_MODEL_FOLDERS_/piano/pianoKey_F_Render.cpp"                                                                 
        //====================================================================================            
        #include "_MODEL_FOLDERS_/piano/pianoKey_F_Sharp_Render.cpp"         
        //====================================================================================        
        #include "_MODEL_FOLDERS_/piano/pianoKey_G_Render.cpp"                                                                 
        //====================================================================================           
        #include "_MODEL_FOLDERS_/piano/pianoKey_G_Sharp_Render.cpp"                                                                 
        //====================================================================================           
       
        #ifdef WIN32
             SwapBuffers( hDC );
        #endif
}

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


#ifdef WIN32 
void ProcessKeyboard()					
{

    if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             pianoKey_Black_LIGHT_POSITION_01[0]         -=  .11;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_Black_LIGHT_POSITION_01[0]         +=  .11;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_Black_LIGHT_POSITION_01[2]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_Black_LIGHT_POSITION_01[2]         -=  .11;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_Black_LIGHT_POSITION_01[1]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_Black_LIGHT_POSITION_01[1]         -=  .11;                                                                            
    }                                                                                                                                 
    //=======================================================================================                                           
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_ATTENUATION                  +=  .001;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_ATTENUATION                  -=  .001;                                                                            
    }                                                                                                                                   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_SHININESS                    +=  1.01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             pianoKey_C_SHININESS                    -=  1.01;                                                                                       
    } 
    //====================================================================================  
    #include "_MODEL_FOLDERS_/piano/pianoKey_C_Keyboard.cpp"                                                               
    //====================================================================================                                          
                            
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("lightPosition.cpp");                                                                                     
        
        outKeys << "  GLfloat     eyePosition[] = {"              << eyePosition[0] << ", "                               
                                                                  << eyePosition[1] << ", "                               
                                                                  << eyePosition[2] << ", " << 1.0 << "};\n";          
        
        outKeys << "  GLfloat     look_LEFT_RIGHT           =  "  << look_LEFT_RIGHT  << ";\n";  
        outKeys << "  GLfloat     look_UP_DOWN              =  "  << look_UP_DOWN   << ";\n";                                    
    }             
        
        //====================================================================================                                          
    
    if (keys['A'])                                                                                                                      
    {                                                                                                                                   
             eyePosition[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['D'])                                                                                                                      
    {	                                                                                                                                  
             eyePosition[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['W'])                                                                                                                      
    {	                                                                                                                                  
             eyePosition[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['S'])                                                                                                                      
    {	                                                                                                                                  
             eyePosition[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['Q'])                                                                                                                      
    {	                                                                                                                                  
             eyePosition[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['E'])                                                                                                                      
    {	                                                                                                                                  
             eyePosition[2]         -=  .01;                                                                                  
    }  

}
#endif


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{
        #ifdef WIN32
            #include "cpp/shutDownWin.cpp"
        #endif 	 
       
        //==================================================================================== 
        #include "_MODEL_FOLDERS_/piano/pianoKey_C_Shutdown.cpp"                                                               
        //====================================================================================           
              
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




