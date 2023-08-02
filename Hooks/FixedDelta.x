/*
	Ensures the game runs at a constant FPS.
	Helps keep TAS recordings accurate.
*/

#import <Foundation/Foundation.h>
#define FIXED_DELTA (1.0f / 60.0f)

%hook Wheely
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook WaterItemEffect
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook TrialLayer
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook TrialGameController
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook TrialBackground
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Trampoline
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook ThemeSelect
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook SpringBoard
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook SoftBox
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook SoftBall
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook OilWell
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook MovingFlat
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook MenuTrialBackground
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook News
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook MenuTrial
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook LevelHelperLoader
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook GlassBall
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook FireBowl
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Conveyor
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook CoinRain
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook ChallengeTurn
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook ChallengeForceRandomOpponent
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Cage
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Buoyant
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook BridgePart
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Bomb
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook Object156
-(void)postUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook CCScheduler
-(void)update:(float)update {
	%orig(FIXED_DELTA);
}
-(void)fixedUpdate:(float)update {
	%orig(FIXED_DELTA);
}
%end

%hook CCDirector
-(BOOL)useFixedTimestep {
	return YES;
}
%end
