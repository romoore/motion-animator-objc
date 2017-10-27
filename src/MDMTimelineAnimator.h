/*
 Copyright 2017-present The Material Motion Authors. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#import <MotionInterchange/MotionInterchange.h>

#import "MDMAnimatableKeyPaths.h"
#import "MDMCoreAnimationTraceable.h"

/**
 An animator adds Core Animation animations to a layer based on a provided motion timing.
 */
NS_SWIFT_NAME(TimelineAnimator)
@interface MDMTimelineAnimator : NSObject <MDMCoreAnimationTraceable>

/**
 The scaling factor to apply to all time-related values.

 For example, a timeScaleFactor of 2 will double the length of all animations.

 1.0 by default.
 */
@property(nonatomic, assign) CGFloat timeScaleFactor;

/**
 If enabled, all animations will be added with their values reversed.

 Disabled by default.
 */
@property(nonatomic, assign) BOOL shouldReverseValues;

/**
 Adds a single animation to the layer with the given timing structure.

 @param timing The timing to be used for the animation.
 @param layer The layer to be animated.
 @param values The values to be used in the animation. Must contain exactly two values. Supported
 UIKit types will be coerced to their Core Animation equivalent. Supported UIKit values include
 UIColor and UIBezierPath.
 @param keyPath The key path of the property to be animated.
 */
- (void)animateWithTiming:(MDMMotionTiming)timing
                  toLayer:(nonnull CALayer *)layer
               withValues:(nonnull NSArray *)values
                  keyPath:(nonnull MDMAnimatableKeyPath)keyPath;

/**
 Adds a single animation to the layer with the given timing structure.

 @param timing The timing to be used for the animation.
 @param layer The layer to be animated.
 @param values The values to be used in the animation. Must contain exactly two values. Supported
 UIKit types will be coerced to their Core Animation equivalent. Supported UIKit values include
 UIColor and UIBezierPath.
 @param keyPath The key path of the property to be animated.
 @param completion The completion handler will be executed once this animation has come to rest.
 */
- (void)animateWithTiming:(MDMMotionTiming)timing
                  toLayer:(nonnull CALayer *)layer
               withValues:(nonnull NSArray *)values
                  keyPath:(nonnull MDMAnimatableKeyPath)keyPath
               completion:(nullable void(^)(void))completion;

#pragma mark - UIViewAnimating

/**
 Reversed indicates that the animation will animate in the reversed direction.
 */
@property(nonatomic, getter=isReversed) BOOL reversed;

/**
 A value between 0 and 1 indicating overall progress of the animation.
 */
@property(nonatomic) CGFloat fractionComplete;

/**
 Starts the animation if the animation was paused.
 */
- (void)startAnimation;

/**
 Pauses the animation if the animation was started.
 */
- (void)pauseAnimation;

@end