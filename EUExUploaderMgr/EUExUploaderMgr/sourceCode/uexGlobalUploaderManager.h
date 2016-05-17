/**
 *
 *	@file   	: uexGlobalUploaderManager.h  in EUExUploaderMgr
 *
 *	@author 	: CeriNo 
 * 
 *	@date   	: Created on 16/5/13.
 *
 *	@copyright 	: 2016 The AppCan Open Source Project.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
#import <Foundation/Foundation.h>
#import "uexUploader.h"
@protocol uexUploaderDelegate;

#define uexGlobalUploaderMgr [uexGlobalUploaderManager sharedManager]


@interface uexGlobalUploaderManager : NSObject<uexUploaderDelegate>


+ (instancetype)sharedManager;

- (void)resumeBackgroundUploaders;

- (BOOL)isIdentifierValid:(NSString *)identifier;
- (void)addGlobalUploader:(uexUploader *)uploader;



- (__kindof uexUploader *)uploaderWithIdentifier:(NSString *)identifier;


- (void)handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)())completionHandler;


- (void)notifyBackgroundUploaderSessionInvalidWithIdentifier:(NSString *)identifier;
- (void)notifyBackgroundUploaderSessionFinishingEventsForBackgroundWithIdentifier:(NSString *)identifier;
@end