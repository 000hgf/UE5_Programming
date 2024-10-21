#pragma once

#include "DrawDebugHelpers.h"

#define MDRAW_SPHERE(location) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), GetActorLocation(), 25.f, 12, FColor::Red, true);

#define MDRAW_SPHERE_COLOR(location,Color) \
if(GetWorld()) \
	DrawDebugSphere(GetWorld(), GetActorLocation(), 25.f, 12, FColor::Color, true);

#define MDRAW_SPHERE_SingleFrame(Location) \
if (GetWorld()) \
	DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);

#define MDRAW_LINE(StartLocation, EndLocation) \
if(GetWorld()) \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);

#define MDRAW_POINT(Location) \
if(GetWorld()) \
	DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Green, true);

#define MDRAW_VECTOR(StartLocation,EndLocation) \
if(GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
	DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Green, true); \
}
#define MDRAW_LINE_SingleFrame(StartLocation, EndLocation) \
if(GetWorld()) \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);

#define MDRAW_POINT_SingleFrame(Location) \
if (GetWorld()) \
	DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, -1.f);

#define MDRAW_VECTOR_SingleFrame(StartLocation, EndLocation) \
if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f); \
	DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, false, -1.f); \
}

DECLARE_LOG_CATEGORY_EXTERN(Mong, Log, All);

// 함수 이름 + 코드 라인 출력
#define HLOG_CALLINFO ( FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")") )

#define HLOG_S( Verbosity ) \
	UE_LOG( Mong, Verbosity, TEXT("%s"), *HLOG_CALLINFO )

#define HLOG( Verbosity, Format, ... ) \
	UE_LOG( Mong, Verbosity, TEXT("%s %s"), *HLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__) )

#define HCHECK( Expr, ... ) \
{ \
	if( !(Expr) ) \
	{ \
		HLOG( Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'") ); \
        return __VA_ARGS__; \
	} \
}
