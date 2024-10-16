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
