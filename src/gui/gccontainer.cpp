/*
 *  The Mana World
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  The Mana World is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Mana World; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 */

#include "gccontainer.h"

#include <iostream>

GCContainer::~GCContainer()
{
    std::list<gcn::Widget*>::iterator i = mDeathList.begin();

    while (i != mDeathList.end()) {
        /* Take care _not_ to modify the list in our _announceDeath method */
        gcn::Widget *w = (*i);
        i = mDeathList.erase(i);
        delete w;
    }

    mDeathList.clear();
}

void GCContainer::add(gcn::Widget *w, bool delChild)
{
    if (delChild) {
        mDeathList.push_back(w);
        std::cout << "add" << w << std::endl;
    }

    Container::add(w);
}

void GCContainer::add(gcn::Widget *w, int x, int y, bool delChild)
{
    if (delChild) {
        mDeathList.push_back(w);
        std::cout << "add" << w << std::endl;
    }

    Container::add(w, x, y);
}

void GCContainer::_announceDeath(gcn::Widget *w)
{
    mDeathList.remove(w);
    std::cout << w << std::endl;
    Container::_announceDeath(w);
}