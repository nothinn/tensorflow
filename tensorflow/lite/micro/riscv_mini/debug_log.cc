/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
// TODO(b/121324430): Add test for DebugLog functions
// TODO(b/121275099): Remove dependency on debug_log once the platform supports
// printf

#include <stdio.h>
#include <string.h>

#define UART_START (*(volatile unsigned int *)0x80000004)
#define UART_END (*(volatile unsigned int *)0x80000008)


void printstr(const char* s)
{
    UART_START = (int)s;
    UART_END = (int)s + strlen(s);


}


extern "C" void DebugLog(const char* s) { 
    printstr(s);
    printstr("\n");
}