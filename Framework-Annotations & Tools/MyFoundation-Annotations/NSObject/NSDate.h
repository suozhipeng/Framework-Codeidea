/*
 * File:  NSDate.h
 * Framework:  Foundation
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 1994-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook: http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


#import <Foundation/NSObject.h>
#import <Foundation/NSNotification.h>

@class NSString;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSNotificationName const NSSystemClockDidChangeNotification API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

typedef double NSTimeInterval;

#define NSTimeIntervalSince1970  978307200.0

@interface NSDate : NSObject <NSCopying, NSSecureCoding>

@property (readonly) NSTimeInterval timeIntervalSinceReferenceDate;

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithTimeIntervalSinceReferenceDate:(NSTimeInterval)ti NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface NSDate (NSExtendedDate)

- (NSTimeInterval)timeIntervalSinceDate:(NSDate *)anotherDate;
@property (readonly) NSTimeInterval timeIntervalSinceNow;
@property (readonly) NSTimeInterval timeIntervalSince1970;

- (id)addTimeInterval:(NSTimeInterval)seconds API_DEPRECATED("Use dateByAddingTimeInterval instead", macos(10.0,10.6), ios(2.0,4.0), watchos(2.0,2.0), tvos(9.0,9.0));
- (instancetype)dateByAddingTimeInterval:(NSTimeInterval)ti API_AVAILABLE(macos(10.6), ios(2.0), watchos(2.0), tvos(9.0));

- (NSDate *)earlierDate:(NSDate *)anotherDate;
- (NSDate *)laterDate:(NSDate *)anotherDate;
- (NSComparisonResult)compare:(NSDate *)other;
- (BOOL)isEqualToDate:(NSDate *)otherDate;

@property (readonly, copy) NSString *description;
- (NSString *)descriptionWithLocale:(nullable id)locale;

@property (class, readonly) NSTimeInterval timeIntervalSinceReferenceDate;

@end

@interface NSDate (NSDateCreation)

+ (instancetype)date;
+ (instancetype)dateWithTimeIntervalSinceNow:(NSTimeInterval)secs;
+ (instancetype)dateWithTimeIntervalSinceReferenceDate:(NSTimeInterval)ti;
+ (instancetype)dateWithTimeIntervalSince1970:(NSTimeInterval)secs;
+ (instancetype)dateWithTimeInterval:(NSTimeInterval)secsToBeAdded sinceDate:(NSDate *)date;

@property (class, readonly, copy) NSDate *distantFuture;
@property (class, readonly, copy) NSDate *distantPast;

- (instancetype)initWithTimeIntervalSinceNow:(NSTimeInterval)secs;
- (instancetype)initWithTimeIntervalSince1970:(NSTimeInterval)secs;
- (instancetype)initWithTimeInterval:(NSTimeInterval)secsToBeAdded sinceDate:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
