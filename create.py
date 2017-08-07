#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys, getopt,os

def main(argv):
   inputfile = ''
   try:
      opts, args = getopt.getopt(argv,'hn:')
   except getopt.GetoptError:
      print('test.py -n <inputfile>')
      sys.exit(2)
   if not len(opts) :
       print('not empty ! test.py -n <name>')
       sys.exit()
   for opt, arg in opts:
      if opt == '-h':
         print('test.py -n <name>')
         sys.exit()
      elif opt in ("-n"):
         inputfile = arg
         if inputfile == ' ':
            print('name is null ')
            sys.exit()

   print('input name is ', inputfile)
   #创建文件夹
   cur_path = os.path.abspath(os.curdir)
   goal_path = os.path.join(cur_path, inputfile);
   try:
       os.mkdir(goal_path)
   except os.error:
       print("Error : Name is exist")
       sys.exit(2)

   ##拷贝模板文件到
   ##读取main 文件
   main_path_in = os.path.join(cur_path,"template","main.cpp");
   all_the_text = open(main_path_in,encoding= 'UTF-8').read()
   all_the_text = all_the_text.replace("$file$",inputfile)

   cmake_path_in = os.path.join(cur_path,"template","CMakeLists.txt");
   c_all_the_text = open(cmake_path_in, encoding='UTF-8').read()
   c_all_the_text = c_all_the_text.replace("$file$", inputfile)

   #写入到新文件夹里
   main_path_out = os.path.join(cur_path,inputfile,inputfile+".cpp");
   cmake_path_out = os.path.join(cur_path,inputfile,"CMakeLists.txt");
   open(main_path_out, 'w',encoding='UTF-8').write(all_the_text);
   open(cmake_path_out, 'w', encoding='UTF-8').write(c_all_the_text);

   #创建文件夹data
   goal_path_data = os.path.join(cur_path, inputfile,"data");
   os.mkdir(goal_path_data)
   open(os.path.join(goal_path_data,"a.in"), 'w', encoding='UTF-8').write("");
   open(os.path.join(goal_path_data, "a.out"), 'w', encoding='UTF-8').write("");

   ## 追加一行

   open(os.path.join(cur_path, "CMakeLists.txt"), 'a+', encoding='UTF-8').write("add_subdirectory("+inputfile+") \n");
   print("ok!")
if __name__ == "__main__":
   main(sys.argv[1:])