/***************************************************************************
    copyright            : (C) 2002-2008 by Jochen Issing
    email                : jochen.issing@isign-softart.de
 ***************************************************************************/

/***************************************************************************
*   This library is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License version   *
*   2.1 as published by the Free Software Foundation.                     *
*                                                                         *
*   This library is distributed in the hope that it will be useful, but   *
*   WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
*   Lesser General Public License for more details.                       *
*                                                                         *
*   You should have received a copy of the GNU Lesser General Public      *
*   License along with this library; if not, write to the Free Software   *
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
*   USA                                                                   *
*                                                                         *
*   Alternatively, this file is available under the Mozilla Public        *
*   License Version 1.1.  You may obtain a copy of the License at         *
*   http://www.mozilla.org/MPL/                                           *
***************************************************************************/

#ifndef MP4TAGSPROXY_H
#define MP4TAGSPROXY_H

#include "taglib_export.h"
#include "mp4fourcc.h"

namespace TagLib
{
  namespace MP4
  {
    // forward declaration(s)
    class ITunesDataBox;
    /*! proxy for mp4 itunes tag relevant boxes
     *
     *  this class works as a proxy for the specific tag boxes
     *  in an mp4 itunes file. the boxes are mired in
     *  the mp4 file structure and stepping through all box layers
     *  is avoided by registration at the proxy object.
     */
    class TAGLIB_EXPORT Mp4TagsProxy
    {
    public:
      /*! enum for all supported box types */
      typedef enum
      {
        title = 0,
        artist,
        albumartist,
        album,
        cover,
        genre,
        gen, /* Also genre */
        year,
        trackno,
        comment,
        grouping,
        composer,
        disk,
        bpm,
        END
      } EBoxType;

      //! constructor
      Mp4TagsProxy();
      //! destructor
      ~Mp4TagsProxy();

      //! function to get the data box for the title
      ITunesDataBox* titleData() const;
      //! function to get the data box for the artist
      ITunesDataBox* artistData() const;
      //! function to get the data box for the album artist
      ITunesDataBox* albumArtistData() const;
      //! function to get the data box for the album
      ITunesDataBox* albumData() const;
      //! function to get the data box for the genre
      ITunesDataBox* genreData() const;
      //! function to get the data box for the year
      ITunesDataBox* yearData() const;
      //! function to get the data box for the track number
      ITunesDataBox* trknData() const;
      //! function to get the data box for the comment
      ITunesDataBox* commentData() const;
      //! function to get the data box for the grouping
      ITunesDataBox* groupingData() const;
      //! function to get the data box for the composer
      ITunesDataBox* composerData() const;
      //! function to get the data box for the disk number
      ITunesDataBox* diskData() const;
      //! function to get the data box for the bpm
      ITunesDataBox* bpmData() const;
      //! function to get the data box for the cover
      ITunesDataBox* coverData() const;

      //! function to register a data box for a certain box type
      void registerBox( EBoxType boxtype, ITunesDataBox* databox );

      //! function to get the data box based on the id
      ITunesDataBox* getDataByType( EBoxType boxtype );

      //! get the fourcc for the given type
      MP4::Fourcc getFourccForType( EBoxType boxtype );

    private:
      class Mp4TagsProxyPrivate;
      //! private data of tags proxy
      Mp4TagsProxyPrivate* d;
    }; // class Mp4TagsProxy
  } // namespace MP4
} // namespace TagLib

#endif // MP4TAGSPROXY_H
