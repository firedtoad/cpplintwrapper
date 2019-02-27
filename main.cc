/*
 * Copyright (c) dietoad@gmail.com All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * main.cc
 *      Author: dietoad@gmail.com
 */

#include <process.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char **argv) {
  std::string last="";
  //modify  the python.exe path and the cpplint.py path to yourself path
  std::string param(
      "G:/msys64/usr/bin/python2.exe G:/msys64/usr/bin/cpplint.py ");
  for (auto i = 1; i < argc; ++i) {
    param += " ";
    param += argv[i];
    last=argv[i];
  }
  std::string path("",256);
  getcwd(&path[0],256);
  std::cout<<path<<std::endl;
  std::cout<<last<<std::endl;
  size_t pos=last.rfind("\\");
  if(pos!=std::string::npos)
  {
      char* dir_name=dirname(&last[0]);
      chdir(dir_name);
  }
  system(param.c_str());
  return 0;
}
