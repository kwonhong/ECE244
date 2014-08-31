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
	${OBJECTDIR}/ResistorList.o \
	${OBJECTDIR}/_ext/675413869/easygl_constants.o \
	${OBJECTDIR}/Rparser.o \
	${OBJECTDIR}/_ext/675413869/graphics.o \
	${OBJECTDIR}/_ext/675413869/easygl.o \
	${OBJECTDIR}/Resistor.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/NodeList.o \
	${OBJECTDIR}/_ext/675413869/easygl.o \
	${OBJECTDIR}/_ext/675413869/graphics.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab4

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab4: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab4 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/ResistorList.o: ResistorList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResistorList.o ResistorList.cpp

${OBJECTDIR}/_ext/675413869/easygl_constants.o: /u/a/kwonhong/NetBeansProjects/Graphics/easygl_constants.h 
	${MKDIR} -p ${OBJECTDIR}/_ext/675413869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/675413869/easygl_constants.o /u/a/kwonhong/NetBeansProjects/Graphics/easygl_constants.h

${OBJECTDIR}/Rparser.o: Rparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rparser.o Rparser.cpp

${OBJECTDIR}/_ext/675413869/graphics.o: /u/a/kwonhong/NetBeansProjects/Graphics/graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/675413869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/675413869/graphics.o /u/a/kwonhong/NetBeansProjects/Graphics/graphics.cpp

${OBJECTDIR}/_ext/675413869/easygl.o: /u/a/kwonhong/NetBeansProjects/Graphics/easygl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/675413869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/675413869/easygl.o /u/a/kwonhong/NetBeansProjects/Graphics/easygl.cpp

${OBJECTDIR}/Resistor.o: Resistor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Resistor.o Resistor.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/Node.o: Node.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Node.o Node.cpp

${OBJECTDIR}/NodeList.o: NodeList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NodeList.o NodeList.cpp

${OBJECTDIR}/_ext/675413869/easygl.o: /u/a/kwonhong/NetBeansProjects/Graphics/easygl.h 
	${MKDIR} -p ${OBJECTDIR}/_ext/675413869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/675413869/easygl.o /u/a/kwonhong/NetBeansProjects/Graphics/easygl.h

${OBJECTDIR}/_ext/675413869/graphics.o: /u/a/kwonhong/NetBeansProjects/Graphics/graphics.h 
	${MKDIR} -p ${OBJECTDIR}/_ext/675413869
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/675413869/graphics.o /u/a/kwonhong/NetBeansProjects/Graphics/graphics.h

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
