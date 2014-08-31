#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/2065761719/ShapeArray.o \
	${OBJECTDIR}/_ext/2065761719/graphics.o \
	${OBJECTDIR}/_ext/2065761719/Circle.o \
	${OBJECTDIR}/_ext/2065761719/Composite.o \
	${OBJECTDIR}/_ext/2065761719/Polygon.o \
	${OBJECTDIR}/_ext/2065761719/Shape.o \
	${OBJECTDIR}/_ext/2065761719/Main.o \
	${OBJECTDIR}/_ext/2065761719/Rectangle.o \
	${OBJECTDIR}/_ext/2065761719/Triangle.o \
	${OBJECTDIR}/_ext/2065761719/easygl.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hello

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hello: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hello ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/2065761719/ShapeArray.o: /u/a/kwonhong/Desktop/Lab6/ShapeArray.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/ShapeArray.o /u/a/kwonhong/Desktop/Lab6/ShapeArray.cpp

${OBJECTDIR}/_ext/2065761719/graphics.o: /u/a/kwonhong/Desktop/Lab6/graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/graphics.o /u/a/kwonhong/Desktop/Lab6/graphics.cpp

${OBJECTDIR}/_ext/2065761719/Circle.o: /u/a/kwonhong/Desktop/Lab6/Circle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Circle.o /u/a/kwonhong/Desktop/Lab6/Circle.cpp

${OBJECTDIR}/_ext/2065761719/Composite.o: /u/a/kwonhong/Desktop/Lab6/Composite.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Composite.o /u/a/kwonhong/Desktop/Lab6/Composite.cpp

${OBJECTDIR}/_ext/2065761719/Polygon.o: /u/a/kwonhong/Desktop/Lab6/Polygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Polygon.o /u/a/kwonhong/Desktop/Lab6/Polygon.cpp

${OBJECTDIR}/_ext/2065761719/Shape.o: /u/a/kwonhong/Desktop/Lab6/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Shape.o /u/a/kwonhong/Desktop/Lab6/Shape.cpp

${OBJECTDIR}/_ext/2065761719/Main.o: /u/a/kwonhong/Desktop/Lab6/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Main.o /u/a/kwonhong/Desktop/Lab6/Main.cpp

${OBJECTDIR}/_ext/2065761719/Rectangle.o: /u/a/kwonhong/Desktop/Lab6/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Rectangle.o /u/a/kwonhong/Desktop/Lab6/Rectangle.cpp

${OBJECTDIR}/_ext/2065761719/Triangle.o: /u/a/kwonhong/Desktop/Lab6/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/Triangle.o /u/a/kwonhong/Desktop/Lab6/Triangle.cpp

${OBJECTDIR}/_ext/2065761719/easygl.o: /u/a/kwonhong/Desktop/Lab6/easygl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2065761719
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2065761719/easygl.o /u/a/kwonhong/Desktop/Lab6/easygl.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hello

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
