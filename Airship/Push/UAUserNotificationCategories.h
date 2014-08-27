/*
 Copyright 2009-2014 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

/**
 * Utility methods to create categories from plist files or NSDictionaries.
 */
@interface UAUserNotificationCategories : NSObject


/**
 * Creates a set of categories from the specified `.plist` file.
 *
 * Categories are defined in a plist dictionary with the category id
 * followed by an NSArray of user nofication action defintions. The
 * action defintions use the same keys as the properties on the action,
 * with the exception of "foreground" mapping to either UIUserNotificationActivationModeForeground
 * or UIUserNotificationActivationModeBackground.
 *
 *  Example:
<pre>
      {
          "category_id" : [
              {
                  "identifier" : "action id",
                  "title" : "action title",
                   "foreground" : @YES,
                  "authenticationRequired" : @NO,
                  "destructive" : @NO
              }]
       }
 </pre>
 */
+ (NSSet *)createCategoriesFromFile:(NSString *)filePath;

/**
 * Creates a user notification category with the specified id and action definition.
 *
 * @param categoryId The category identifier
 * @param actionDefinitions An array of user notification action dictionaries used
 * to construct UIUserNotificationAction for the category.
 */
+ (UIUserNotificationCategory *)createCategory:(NSString *)categoryId actions:(NSArray *)actionDefinitions;
@end