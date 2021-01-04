/** -*- mode:objc -*-
 *
 * Minimal example to test installation of GNUstep
 *
 */

#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>

int main(int argc, char *argv[], char **env)
{
  NSLog(@"Hello World!\n");

  NSString *greeting = @"Hello from a dispatch event";

  dispatch_time_t delay = dispatch_time(DISPATCH_TIME_NOW, 2.0*NSEC_PER_SEC);

  dispatch_after(delay, dispatch_get_global_queue(0,0), ^(void) {
      NSLog(@"dispatch: %@", greeting);
      exit(0);
    });

  
  [[NSRunLoop mainRunLoop] run];
}

