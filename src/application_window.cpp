//----------------------------------------------------------------------
// file: application_window.cpp
// description: Class for initializing an OpenGL window with the SDL
//              used by the OpenGL tutorials at www.tomprogs.at
//----------------------------------------------------------------------
// Copyright (c) 2008-2011, Thomas Geymayer
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
//----------------------------------------------------------------------

#include "application_window.h"

#include "dep.h"

namespace TomprogsTutorial_
{

  //--------------------------------------------------------------------
  ApplicationWindow::ApplicationWindow(
                       int width,
                       int height, int bpp ):
                         _width  ( width                  ),
                         _height ( height                 ),
                         _bpp    ( bpp                    ),
                         _caption( "Tomprogs Application" ),
                         _state  ( 0                      )
  {

  }

  //--------------------------------------------------------------------
  ApplicationWindow::~ApplicationWindow()
  {
    destroy();
  }

  //--------------------------------------------------------------------
  bool ApplicationWindow::create()
  {
    // check if allready opened a window
    if( _state & OPENED_WINDOW )
      destroy();

    if(    !SDL_WasInit( SDL_INIT_VIDEO ) )
      SDL_InitSubSystem( SDL_INIT_VIDEO );

    SDL_WM_SetCaption(   _caption.c_str(), NULL );

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    _surface =
      SDL_SetVideoMode(
        _width, _height, _bpp,
        SDL_OPENGL | ( (_state & FULL_SCREEN) ? SDL_FULLSCREEN : 0 ) );

    if( !_surface ) return false;

    // disable cursor
    SDL_ShowCursor( 0 );

    _state |= OPENED_WINDOW;

    return true;
  }

  //--------------------------------------------------------------------
  bool ApplicationWindow::destroy()
  {
    // return if no window is opened
    if( !(_state & OPENED_WINDOW) ) return true;

    SDL_FreeSurface( _surface );

    _state &= ~OPENED_WINDOW;

    return true;
  }

  //--------------------------------------------------------------------
  void ApplicationWindow::setResolution( int width, int height )
  {
    _width  = width;
    _height = height;
  }

  //--------------------------------------------------------------------
  void ApplicationWindow::setColorDepth( int bpp )
  {
    _bpp = bpp;
  }

  //--------------------------------------------------------------------
  void ApplicationWindow::setCaption( const std::string& caption )
  {
    _caption = caption;
  }

  //--------------------------------------------------------------------
  void ApplicationWindow::setFullscreen( bool enable )
  {
    if( enable )
    {
      _state |= FULL_SCREEN;
    }
    else
    {
      _state &= ~FULL_SCREEN;
    }
  }

  //--------------------------------------------------------------------
  SDL_Surface* ApplicationWindow::getSurface()
  {
    return _surface;
  }

} // namespace TomprogsTutorial_

