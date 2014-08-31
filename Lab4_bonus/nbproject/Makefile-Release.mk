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
	${OBJECTDIR}/_ext/1279040995/Rparser.o \
	${OBJECTDIR}/_ext/1279040995/Node.o \
	${OBJECTDIR}/_ext/1279040995/graphics.o \
	${OBJECTDIR}/_ext/1279040995/NodeList.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/_ext/1279040995/Resistor.o \
	${OBJECTDIR}/_ext/1279040995/ResistorList.o \
	${OBJECTDIR}/_ext/1279040995/easygl.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawcircuit

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawcircuit: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawcircuit ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1279040995/Rparser.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/Rparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/Rparser.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/Rparser.cpp

${OBJECTDIR}/_ext/1279040995/Node.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/Node.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/Node.cpp

${OBJECTDIR}/_ext/1279040995/graphics.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/graphics.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/graphics.cpp

${OBJECTDIR}/_ext/1279040995/NodeList.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/NodeList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/NodeList.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/NodeList.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/_ext/1279040995/Resistor.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/Resistor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/Resistor.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/Resistor.cpp

${OBJECTDIR}/_ext/1279040995/ResistorList.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/ResistorList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/ResistorList.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/ResistorList.cpp

${OBJECTDIR}/_ext/1279040995/easygl.o: /u/a/kwonhong/NetBeansProjects/DrawCircuit/easygl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1279040995
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1279040995/easygl.o /u/a/kwonhong/NetBeansProjects/DrawCircuit/easygl.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawcircuit

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
