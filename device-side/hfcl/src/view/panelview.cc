/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018, 2019 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
** panelview.cc: The implementation of PanelView class.
**
** Create by WEI Yongming at 2018/10/27
*/

#include "view/viewfactory.h"
#include "view/panelview.h"
#include "graphics/image.h"
#include "drawable/imagedrawable.h"

namespace hfcl {

/*
 * The PanelView is intended to support the tags which are
 * defined as 'Sectioning content' (such as `article`) by HTML5
 * or some tags defined as 'Palpable content':
 *
 * https://www.w3.org/TR/html52/dom.html#sectioning-content
 * https://www.w3.org/TR/html52/dom.html#palpable-content
 *
 * In HVML, the following tags are supported by ContentView:
 *
 * - `article`, `aside`, `nav`, `section`
 * - `header`, `footer`, `main`, `div`
 * - `ul`, `ol`, `dl`
 * - `address`
 * - `blockquote`
 * - `figure`
 * - `details`
 */

PanelView::PanelView(const char* vtag, const char* vtype,
            const char* vclass, const char* vname, int vid)
    : ViewContainer(vtag, vtype, vclass, vname, vid)
{
}

PanelView::~PanelView()
{
}

AUTO_REGISTER_VIEW(article, PanelView);
AUTO_REGISTER_VIEW(aside, PanelView);
AUTO_REGISTER_VIEW(nav, PanelView);
AUTO_REGISTER_VIEW(section, PanelView);
AUTO_REGISTER_VIEW(header, PanelView);
AUTO_REGISTER_VIEW(footer, PanelView);
AUTO_REGISTER_VIEW(ul, PanelView);
AUTO_REGISTER_VIEW(ol, PanelView);
AUTO_REGISTER_VIEW(dl, PanelView);
AUTO_REGISTER_VIEW(address, PanelView);
AUTO_REGISTER_VIEW(bockquote, PanelView);
AUTO_REGISTER_VIEW(figure, PanelView);
AUTO_REGISTER_VIEW(details, PanelView);

} // namespace hfcl
