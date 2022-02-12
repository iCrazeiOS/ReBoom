/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Boom-Structs.h"
#import "UIApplicationDelegate.h"
#import "CCDirectorDelegate.h"
#import "HSGameCenterManagerDelegate.h"

@class UINavigationController, UILocalNotification, NSManagedObjectContext, NSManagedObjectModel, NSPersistentStoreCoordinator, NSDictionary, NSString, UIWindow, CCDirectorIOS;
@protocol AppRemoteNotifications;

__attribute__((visibility("hidden")))
@interface AppController : XXUnknownSuperclass <UIApplicationDelegate, CCDirectorDelegate, HSGameCenterManagerDelegate> {
	UIWindow* window_;
	UINavigationController* navController_;
	CCDirectorIOS* director_;
	NSDictionary* applicationNotificationLaunchOptions;
	UILocalNotification* applicationLocalNotification;
	id<AppRemoteNotifications> remoteNotificationsDelegate;
	BOOL devEnvironment;
	BOOL iapLoaded;
	BOOL askedForGameCenter;
	NSManagedObjectContext* __managedObjectContext;
	NSManagedObjectModel* __managedObjectModel;
	NSPersistentStoreCoordinator* __persistentStoreCoordinator;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign, nonatomic) NSPersistentStoreCoordinator* persistentStoreCoordinator;
@property(readonly, assign, nonatomic) NSManagedObjectModel* managedObjectModel;
@property(readonly, assign, nonatomic) NSManagedObjectContext* managedObjectContext;
@property(assign, nonatomic) BOOL iapLoaded;
@property(readonly, assign) CCDirectorIOS* director;
@property(readonly, assign) UINavigationController* navController;
@property(retain, nonatomic) UIWindow* window;
-(void).cxx_destruct;
-(unsigned)application:(id)application supportedInterfaceOrientationsForWindow:(id)window;
-(id)applicationCachesDirectory;
-(id)applicationDocumentsDirectory;
-(void)resetApp;
-(void)resetManagedObjectContext;
-(void)saveContext;
-(void)applicationSignificantTimeChange:(id)change;
-(void)applicationDidReceiveMemoryWarning:(id)application;
-(void)checkIfUpgraded;
-(void)applicationWillTerminate:(id)application;
-(void)application:(id)application performFetchWithCompletionHandler:(id)completionHandler;
-(void)removeRemoteNotificationsDelegate:(id)delegate;
-(void)setRemoteNotificationsDelegate:(id)delegate;
-(BOOL)handleLocalNotification:(id)notification userTriggered:(BOOL)triggered;
-(void)application:(id)application didReceiveLocalNotification:(id)notification;
-(BOOL)handlePushNotification:(id)notification userTriggered:(BOOL)triggered;
-(void)application:(id)application didReceiveRemoteNotification:(id)notification;
-(void)application:(id)application didFailToRegisterForRemoteNotificationsWithError:(id)error;
-(void)application:(id)application didRegisterForRemoteNotificationsWithDeviceToken:(id)deviceToken;
-(BOOL)handleUrl:(id)url;
-(BOOL)application:(id)application openURL:(id)url sourceApplication:(id)application3 annotation:(id)annotation;
-(void)applicationWillEnterForeground:(id)application;
-(void)applicationDidEnterBackground:(id)application;
-(void)applicationDidBecomeActive:(id)application;
-(void)applicationWillResignActive:(id)application;
-(BOOL)shouldAutorotateToInterfaceOrientation:(int)interfaceOrientation;
-(void)gameCenterAchievementsSyncComplete:(id)complete;
-(void)newsInit;
-(void)launchGame;
-(void)application:(id)application didRegisterUserNotificationSettings:(id)settings;
-(void)registerForRemoteNotification;
-(BOOL)application:(id)application didFinishLaunchingWithOptions:(id)options;
-(id)urlScheme;
@end

