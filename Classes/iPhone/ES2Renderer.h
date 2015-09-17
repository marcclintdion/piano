

GLfloat eyePosition[3];
GLfloat pianoKey_C_POSITION[4];
GLfloat pianoKey_C_ROTATE[4];
GLfloat pianoKey_Black_LIGHT_POSITION_01[4];

//================================================================
//#import <AVFoundation/AVFoundation.h>
//-------------------
//AVAudioPlayer *laser;
//-------------------

//====================================

#include <AudioToolbox/AudioToolbox.h>
SystemSoundID C2;
SystemSoundID D2;
SystemSoundID E2;
SystemSoundID F2;
SystemSoundID G2;
SystemSoundID A2;
SystemSoundID B2;
//------------------



#import <QuartzCore/QuartzCore.h>

#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>



//----------------------------------------------------------


GLint      backingWidth;
GLint      backingHeight;

GLboolean runOnce;


@interface ES2Renderer : NSObject
{
	
}

- (ES2Renderer* ) initWithContext:(EAGLContext *) context AndDrawable:(id<EAGLDrawable>)drawable;

- (BOOL)resizeFromLayer:(CAEAGLLayer*)layer;

- (void) render;
   void  shutDownGL(void);
   void  InitGL(void);
   void  RenderGL(void);

@end

