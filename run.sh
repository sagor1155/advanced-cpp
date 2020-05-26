#!/bin/bash

PNAME="smart-pointer/shared-pointer.cpp"
BUILDCMD="g++ -std=c++14 -pthread -o a ${PNAME}"
OBJFILE='a'

RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
LCYAN='\033[1;36m'
NC='\033[0m' # No Color

echo -e "${NC}"
echo -e "Removing object file"
sudo rm ${OBJFILE}

echo -e "${BLUE}-----------------------------------"
echo -e "Compiling the program: ${PNAME}"
echo -e "-----------------------------------${NC}"
echo -e "Build Command: ${LCYAN}${BUILDCMD}${NC}"
echo -e "${BLUE}-----------------------------------${NC}"

eval "${BUILDCMD}"

echo -e "${BLUE}-----------------------------------"
echo -e "Executing the program: ${PNAME}${NC}"
echo -e "${YELLOW}-----------------------------------"
echo -e "Program started"
echo -e "-----------------------------------${NC}${LCYAN}"

./${OBJFILE}

echo -e "${NC}${YELLOW}-----------------------------------"
echo -e "Program Ended"
echo -e "-----------------------------------${NC}"
echo -e "${NC}"