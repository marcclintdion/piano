/*
 File: iPhoneGLEssentialPracticesAppDelegate.m
 Abstract: The application delegate.
 Version: 1.0
 
 */

//#import <UIKit/UISwipeGestureRecognizer.h>
//#import <UIKit/UITapGestureRecognizer.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import "iPhoneGLEssentialsAppDelegate.h"

GLuint   viewFramebuffer;



#import "EAGLView.h"
#import <GLKit/GLKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


//====================================================================================================================================================
@implementation iPhoneGLEssentialPracticesAppDelegate
//===================================================



@synthesize window;
@synthesize glView;



//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


//----------------------------------------------------------------------------------------------------------------------------------------------------
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{    
    
        //================================================================================================================================================   
        //TestViewController = [[[TestViewController alloc] initWithNibName:@"EAGLView" bundle:nil] autorelease];
        //self.window.rootViewController = self.TestViewController;
        //self.window.rootViewController = EAGLView;
        //self.window.rootViewController = nil;
        //--------------------------------------------
        bounds = window.bounds;
        
        view = [[UIView alloc] initWithFrame: bounds];
        view.multipleTouchEnabled   = YES;
        view.userInteractionEnabled = YES;    
        //--------------------------------------------
        [window addSubview: view];        
        //================================================================================================================================================
        
        
        
        //================================================================================================================================================
        //--------------------------------
        //################################__________from video -> session 223 - Building advanced gesture Recognizers.__________##########################
        //--------------------------------
        //################################______________UIGestureRecognizer.h________UIGestureRecognizerSubclass.h__________________######################
        //--------------------------------
        //================================================================================================================================================
        //    -[UIGestureRecognizerDelegate gestureRecognizer: shouldRecognizeSimultaneouslyWithGestureRecognizer:]
        //    -[UIGestureRecognizer shouldPreventGestureRecognizer:]
        //    -[UIGestureRecognizer shouldBePreventedByGestureRecognizer:]
        //    -[singleTap requireGestureToFail:doubleTap]
        //---------------------------------------------------------------------------------------------------------------------------   
        //    -(void)addGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer 
        //    -(void)removeGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer         
        //---------------------------------------------------------------------------------------------------------------------------
        //    -(CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView*)view;
        //---------------------------------------------------------------------------------------------------------------------------
        //    button1TapTime = CACurrentMediaTime();
        //    http://stackoverflow.com/questions/12708184/handle-taps-in-two-different-points-at-a-same-time-via-uigesturerecognizer ->answered->tarmes
        //---------------------------------------------------------------------
        //    https://developer.apple.com/library/safari/#documentation/AppleApplications/Reference/SafariWebContent/HandlingEvents/HandlingEvents.html
        //---------------------------------------------------------------------        
        //    ontouchstart="touchStart(event);"
        //    ontouchmove="touchMove(event);"
        //    ontouchend="touchEnd(event);"
        //    ontouchcancel="touchCancel(event);"
        // 
        //    Alternatively, register handlers in JavaScript as follows:
        //    element.addEventListener("touchstart", touchStart, false);
        //    element.addEventListener("touchmove", touchMove, false);
        //    element.addEventListener("touchend", touchEnd, false);
        //    element.addEventListener("touchcancel", touchCancel, false);
        //---------------------------------------------------------------------          
        
        //------------------------------------------------------------------------------------------------------------------------------------------------
/*        //################################################################################################################################################
        UIPanGestureRecognizer *panRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panDetected:)];
        [view addGestureRecognizer:panRecognizer];
        //================================================================================================================================================  
        UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapDetected:)];
        tapRecognizer.numberOfTapsRequired = 1;
        [view addGestureRecognizer:tapRecognizer];     
        //================================================================================================================================================  
        UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doubleTapDetected:)];
        doubleTapRecognizer.numberOfTapsRequired = 2;
        [view addGestureRecognizer:doubleTapRecognizer];        
        //================================================================================================================================================  
       UIPinchGestureRecognizer *pinchRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchDetected:)];
        [view addGestureRecognizer:pinchRecognizer];    
        //================================================================================================================================================           
        UIRotationGestureRecognizer *rotationRecognizer = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rotationDetected:)];
        [view addGestureRecognizer:rotationRecognizer];
        //================================================================================================================================================       
        UISwipeGestureRecognizer *swipeRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipeDetected:)];
        swipeRecognizer.direction = UISwipeGestureRecognizerDirectionRight;
        [view addGestureRecognizer:swipeRecognizer];
*/        //================================================================================================================================================           
        UILongPressGestureRecognizer *longpressGesture1 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler1:)];
        longpressGesture1.minimumPressDuration = 0;
        longpressGesture1.numberOfTouchesRequired = 1;
        [view addGestureRecognizer:longpressGesture1];    
        //================================================================================================================================================           
        UILongPressGestureRecognizer *longpressGesture2 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler2:)];
        longpressGesture2.minimumPressDuration = 0;
        longpressGesture2.numberOfTouchesRequired = 2;
        [view addGestureRecognizer:longpressGesture2];            
        //================================================================================================================================================           
        UILongPressGestureRecognizer *longpressGesture3 = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressHandler3:)];
        longpressGesture3.minimumPressDuration = 0;
        longpressGesture3.numberOfTouchesRequired = 3;
        [view addGestureRecognizer:longpressGesture3];            
        
/*        
        //================================================================================================================================================          
        UITapGestureRecognizer *TwoSimultaneousTapsRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapTwoSimultaneousTaps:)];
        TwoSimultaneousTapsRecognizer.numberOfTapsRequired = 1;
        TwoSimultaneousTapsRecognizer.numberOfTouchesRequired = 2;
        [view addGestureRecognizer:TwoSimultaneousTapsRecognizer];        
        //================================================================================================================================================          
        UITapGestureRecognizer *ThreeSimultaneousTapsRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapThreeSimultaneousTaps:)];
        ThreeSimultaneousTapsRecognizer.numberOfTapsRequired = 1;
        ThreeSimultaneousTapsRecognizer.numberOfTouchesRequired = 3;
        [view addGestureRecognizer:ThreeSimultaneousTapsRecognizer];           
        
*/        
        
        
        //================================================================================================================================================
        [glView startAnimation];
        [window makeKeyAndVisible];
    
        return YES;
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
- (void)longPressHandler1:(UILongPressGestureRecognizer *)longpressGesture1 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        CGPoint location =  [longpressGesture1  locationInView:self->view];
        //=================================================================================================================    
        
        
        if (longpressGesture1.state == UIGestureRecognizerStateBegan)
        {
                //=================================================================================================================       
                if(location.y >= 0.0 && location.y < (backingHeight/7.0) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(C2); 
                }
                //=================================================================================================================
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(D2); 
                }
                //=================================================================================================================        
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(E2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(F2); 
                }
                //=================================================================================================================           
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(G2); 
                }
                //=================================================================================================================            
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(A2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(B2); 
                }
                //=================================================================================================================    
                
        } 
   
        
}
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
- (void)longPressHandler2:(UILongPressGestureRecognizer *)longpressGesture2 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        CGPoint location =  [longpressGesture2  locationInView:self->view];
        //=================================================================================================================    
        
        
        if (longpressGesture2.state == UIGestureRecognizerStateBegan)
        {
                //=================================================================================================================       
                if(location.y >= 0.0 && location.y < (backingHeight/7.0) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(C2); 
                }
                //=================================================================================================================
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(D2); 
                }
                //=================================================================================================================        
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(E2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(F2); 
                }
                //=================================================================================================================           
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(G2); 
                }
                //=================================================================================================================            
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(A2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(B2); 
                }
                //=================================================================================================================    
                
        } 
        
        
}
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
- (void)longPressHandler3:(UILongPressGestureRecognizer *)longpressGesture3 
{
        //UIGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
        //UIGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to UIGestureRecognizerStatePossible
        //UIGestureRecognizerStateCancelled   // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to UIGestureRecognizerStatePossible
        
        //===============================================================================
        CGPoint location =  [longpressGesture3  locationInView:self->view];
        //=================================================================================================================    
        
        
        if (longpressGesture3.state == UIGestureRecognizerStateBegan)
        {
                //=================================================================================================================       
                if(location.y >= 0.0 && location.y < (backingHeight/7.0) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(C2); 
                }
                //=================================================================================================================
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(D2); 
                }
                //=================================================================================================================        
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(E2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(F2); 
                }
                //=================================================================================================================           
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(G2); 
                }
                //=================================================================================================================            
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(A2); 
                }
                //=================================================================================================================               
                if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
                {
                        AudioServicesPlaySystemSound(B2); 
                }
                //=================================================================================================================    
                
        } 
        
        
}
      
/*        
- (void)rotationDetected:(UIRotationGestureRecognizer *)rotationRecognizer
{
        //===============================================================================
        //CGPoint location =  [rotationRecognizer  locationInView:self->view];
        //=================================================================================================================       
}   
*/
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)tapDetected:(UITapGestureRecognizer *)tapRecognizer
{      
        //===============================================================================
        CGPoint location =  [tapRecognizer  locationInView:self->view];
        //=================================================================================================================    

        //=================================================================================================================       
        if(location.y >= 0.0 && location.y < (backingHeight/7.0) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //=================================================================================================================           
     
        //backingHeight
        //backingWidth
}

*/

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
-(void)handleTapTwoSimultaneousTaps:(UITapGestureRecognizer*)TwoSimultaneousTapsRecognizer
{
        
        //===============================================================================
        //CGPoint location =  [TwoSimultaneousTapsRecognizer  locationInView:self->view];
        //=================================================================================================================          
        
        CGPoint point1 = [TwoSimultaneousTapsRecognizer locationOfTouch:0 inView:self->view];
        CGPoint point2 = [TwoSimultaneousTapsRecognizer locationOfTouch:1 inView:self->view];           

        //=================================================================================================================       
        if(point1.y >= 0.0 && point1.y < (backingHeight/7.0) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //###########################################################################################################################################################################    
        if(point2.y >= 0.0 && point2.y < (backingHeight/7.0) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //###########################################################################################################################################################################    

}
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

-(void)handleTapThreeSimultaneousTaps:(UITapGestureRecognizer*)ThreeSimultaneousTapsRecognizer
{
        
        //===============================================================================
        //CGPoint location =  [ThreeSimultaneousTapsRecognizer  locationInView:self->view];
        //=================================================================================================================          
        
        CGPoint point1 = [ThreeSimultaneousTapsRecognizer locationOfTouch:0 inView:self->view];
        CGPoint point2 = [ThreeSimultaneousTapsRecognizer locationOfTouch:1 inView:self->view];           
        CGPoint point3 = [ThreeSimultaneousTapsRecognizer locationOfTouch:2 inView:self->view];           
        
        //=================================================================================================================       
        if(point1.y >= 0.0 && point1.y < (backingHeight/7.0) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(point1.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point1.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && point1.x >= 0.0 && point1.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //###########################################################################################################################################################################    
        if(point2.y >= 0.0 && point2.y < (backingHeight/7.0) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(point2.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point2.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && point2.x >= 0.0 && point2.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //###########################################################################################################################################################################    
        if(point3.y >= 0.0 && point3.y < (backingHeight/7.0) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); 
        }
        //=================================================================================================================
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(point3.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && point3.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && point3.x >= 0.0 && point3.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        
}
*/
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)doubleTapDetected:(UITapGestureRecognizer *)doubleTapRecognizer
{
        
        //===============================================================================
        //CGPoint location =  [doubleTapRecognizer  locationInView:self->view];
        //=================================================================================================================       
     
        
} 
*/
//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================
/*
- (void)panDetected:(UIPanGestureRecognizer *)panRecognizer
{
    
    
        //===============================================================================
        CGPoint location =  [panRecognizer  locationInView:self->view];
        //---------------------------------------------------------------
        
        
        
        //=================================================================================================================       
        if(location.y >= 0.0 && location.y < (backingHeight/7.0) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(C2); AudioServicesPlaySystemSound(A2);
        }
        //=================================================================================================================
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*0.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(D2); 
        }
        //=================================================================================================================        
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*1.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(E2); 
        }
        //=================================================================================================================               
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*2.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(F2); 
        }
        //=================================================================================================================           
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*3.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(G2); 
        }
        //=================================================================================================================            
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*4.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(A2); 
        }
        //=================================================================================================================               
        if(location.y >= ((backingHeight/7.0)+(backingHeight/7.0*5.0)) && location.y < ((backingHeight/7.0)+(backingHeight/7.0*6.0)) && location.x >= 0.0 && location.x < backingWidth * 0.48)
        {
                AudioServicesPlaySystemSound(B2); 
        }
        //=================================================================================================================           
   
       
        //###############################################################################################################
        //------
        //------------------------------------------ THIS COULD BE MOVED TO DOUBLE TAP INSTEAD OF SWITCHING BETWEEN 
        //------------------------------------------ EDGE DETECTION AND CONFIGURATION CONTROLS AND DEBUGGER DIALOGUE
        //------        
        
         //       CGPoint translation = [panRecognizer velocityInView: view];   
        
         //       pianoKey_Black_LIGHT_POSITION_01[1] += translation.x * 0.0001;        
         //       pianoKey_Black_LIGHT_POSITION_01[2] += translation.y * 0.0001;
        
          //      NSLog(@"pianoKey_Black_LIGHT_POSITION_01[1]: %f", pianoKey_Black_LIGHT_POSITION_01[1]);   
           //     NSLog(@"pianoKey_Black_LIGHT_POSITION_01[2]: %f", pianoKey_Black_LIGHT_POSITION_01[2]);        
        //
        //###############################################################################################################
        //------
        
        
        //---------------------------------------------------------------------------------------------------------------- 

}
*/

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)pinchDetected:(UIPinchGestureRecognizer *)pinchRecognizer
{
        //=========================================================================================
        //CGFloat scale = pinchRecognizer.scale;
        //----------------------------------------------        
        //pinchRecognizer.scale = 1.0;
        //----------------------------------------------
        //eyePosition[2] /= scale;   
        //NSLog(@"eyePosition[2]: %f", eyePosition[2]);   
        //=========================================================================================
        
        
        
        
        //=========================================================================================
        //POSITION_ICON_GLOBAL[2] /= scale;   
        //NSLog(@"POSITION_ICON_GLOBAL: %f",POSITION_ICON_GLOBAL[2]);  
        //-----------------------------------------------------------------------------------------//_____  self->view.transform = CGAffineTransformScale(self->view.transform, scale, scale);
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================



//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationWillResignActive:(UIApplication *)application
{
         /*
         Sent when the application is about to move from active to inactive state. 
         This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) 
         or when the user quits the application and it begins the transition to the background state.
         Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
         */
    
	[glView stopAnimation];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationDidEnterBackground:(UIApplication *)application 
{
         /*
         Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application 
         to its current state in case it is terminated later. 
         If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
         */
	
	[glView stopAnimation];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationWillEnterForeground:(UIApplication *)application 
{
         /*
         Called as part of transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
         */
	
	[glView startAnimation];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationDidBecomeActive:(UIApplication *)application 
{
         /*
         Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally 
         refresh the user interface.
         */
	
	[glView startAnimation];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationWillTerminate:(UIApplication *)application 
{
         /*
         Called when the application is about to terminate.
         See also applicationDidEnterBackground:.
         */
	
	[glView stopAnimation];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application 
{
        /*
        Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
        */
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================


- (void)dealloc 
{
    
        //------------------------------
        [glView release];
        [window release];
        [view release];   
        //------------------------------
    
    
        //------------------------------
    
        [super dealloc];
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================





@end
















