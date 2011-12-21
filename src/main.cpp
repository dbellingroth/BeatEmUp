//------------------------------------------------------------------------------
// file: tomprogs_opengl_tutorial_04.cpp
// description: Demo program for the Tutorial
//              'C++ OpenGL Tutorials - Transformationen'
//              at www.tomprogs.at
//------------------------------------------------------------------------------
// Copyright (c) 2008 - 2010, Thomas Geymayer
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
//      copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided
//      with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------
#include "dep.h"

#include <iostream>

#include "application_window.h"

using std::cerr;
using std::endl;

enum Transformations
{
  NONE,
  TRANSLATE,
  ROTATE,
  SCALE,
  ROTATE_TRANSLATE,
  TRANSLATE_ROTATE,
  SCALE_TRANSLATE,
  TRANSLATE_SCALE,
  SCALE_ROTATE,
  ROTATE_SCALE,
};

int state = NONE;

// Polling-Funktion für Events
bool pollEvents()
{
  SDL_Event event;

  while( SDL_PollEvent(&event) ) // Nächste Nachricht holen
  {
    switch(event.type)
    {
      case SDL_KEYDOWN:
        if( event.key.keysym.sym == SDLK_t ) ++state; // wenn [T] gedrückt
        break;                                        // nächster Zustand
      case SDL_QUIT:
        return false; // Programm sollte beendet werden
      default:
        break;
    }
  }

  return true;
}

int main(int argc, char **argv)
{
  if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) // Initialisieren des SDL Video
                                        // Subsystems
  {
    cerr << "Die SDL konnte nicht initalisiert werden ("
         << SDL_GetError() << ")" << endl;
    return 1;
  }

  // Ein Fenster mit 800*600 Pixeln bei 32 Bit Farbtiefe anlegen
  TomprogsTutorial_::ApplicationWindow *game_window =
    new TomprogsTutorial_::ApplicationWindow( 800, 600, 32 );

  // Den Fenstertitel setzen
  game_window->setCaption( "SDL - Test" );

  // Und schließlich das Fenster erzeugen lassen
  game_window->create();

  glClearColor( 1, 0.95, 0.95, 1 ); // Farbe zum Löschen setzen
  glEnable( GL_DEPTH_TEST );        // Z-Buffer und Tiefentest aktivieren

  //--------------------------
  // Die Projektion festlegen:
  //--------------------------

  glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -5.3, 5.3, -4, 4, 0.5, 1.5 );

  // Die Endlosschleife
  while(true)
  {
    if( !pollEvents() ) break; // Nachrichten verarbeiten

    // Bildpuffer und Z-Buffer zurücksetzen:
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW ); // Die Transformationsmatrix
      glLoadIdentity();           // zurücksetzen...

    //--------------------------------
    // Ein Koordinatensystem zeichnen:
    //--------------------------------

    glBegin( GL_LINES );

      glColor3f(1,0,0);
        glVertex3f(8,0,-1.1);
        glVertex3f(-8,0,-1.1);

      glColor3f(0,0,1);
        glVertex3f(0,8,-1.1);
        glVertex3f(0,-8,-1.1);

    glEnd();

    //----------------------
    // Die Transformationen:
    //----------------------

    switch( state )
    {
      case NONE:
        break;
      case TRANSLATE:
        glTranslatef(3,0,0);
        break;
      case ROTATE:
        glRotatef(50,0,0,1);
        break;
      case SCALE:
        glScalef(0.5,2,1);
        break;
      case ROTATE_TRANSLATE:
        glTranslatef(3,0,0);
        glRotatef(50,0,0,1);
        break;
      case TRANSLATE_ROTATE:
        glRotatef(50,0,0,1);
        glTranslatef(3,0,0);
        break;
      case SCALE_TRANSLATE:
        glScalef(0.5,2,1);
        glTranslatef(3,0,0);
        break;
      case TRANSLATE_SCALE:
        glTranslatef(3,0,0);
        glScalef(0.5,2,1);
        break;
      case SCALE_ROTATE:
        glScalef(0.5,2,1);
        glRotatef(50,0,0,1);
        break;
      case ROTATE_SCALE:
        glRotatef(50,0,0,1);
        glScalef(0.5,2,1);
        break;
      default:
        state = NONE;
    }

    //-----------------------
    // Das Rechteck zeichnen:
    //-----------------------

    glBegin( GL_QUADS );

      glColor3f(0.3, 0.9, 0.3);
        glVertex3f( 1.5,  0.5,  -1);
        glVertex3f(-1.5,  0.5,  -1);
      glColor3f(0.9, 0.3, 0.3);
        glVertex3f(-1.5, -0.5,  -1);
        glVertex3f( 1.5, -0.5,  -1);

    glEnd();

    SDL_GL_SwapBuffers();
  }

  SDL_Quit();

  return 0;
}
