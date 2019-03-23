//
//  shader.cpp
//  dungeon_mapper
//
//  Created by Clayton Knittel on 9/20/18.
//  Copyright © 2018 Clayton Knittel. All rights reserved.
//

#ifndef shader_h
#define shader_h

#include <GL/glew.h>

class program {
public:
    program(const char * vertex_shader_path, const char * fragment_shader_path);
    void use();
    GLuint programLoc();
    GLuint uniformLoc(const char *name);
    
private:
    GLuint prog;
};


class shader {
public:
    shader(const char *code_loc, GLint type);
    GLuint tag();
    
private:
    GLuint self;
};



#endif /* shader_h */
