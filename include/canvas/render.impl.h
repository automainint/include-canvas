/*  canvas/render.impl.h
 *
 *  Copyright (c) 2021 Mitya Selivanov
 *
 *  This file is part of IncludeCanvas.
 */

#pragma once

namespace canvas
{
    inline void finalize()
    {
        if (!_ref().hWnd)
        {
            std::cerr << "No window." << std::endl;
        }
        else
        {
            auto hDC = GetDC(_ref().hWnd);

            if (!hDC)
            {
                std::cerr << "GetDC failed." << std::endl;
            }
            else
            {
                _paint_to(hDC);

                ReleaseDC(_ref().hWnd, hDC);
            }
        }
    }
}
