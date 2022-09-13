/*
    Makes the game connect to the custom server, as the original server is dead.
*/

#import "Headers/Common.h"
#define SERVER_HOST @"https://boom.markstam.eu"

%hook Player
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook HSGameConfiguration
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook HSNews
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook ChallengeClient
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook TournamentsClient
+(void)setTournamentUrl:(id)url {
	%orig([NSString stringWithFormat:@"%@/tournaments/", SERVER_HOST]);
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if (!([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"])) return;
	%init;
}

