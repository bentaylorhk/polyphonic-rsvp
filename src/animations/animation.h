/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2025
 */

#pragma once

#include <ncurses.h>

#include <chrono>
#include <memory>
#include <random>
#include <string>

#include "../util/common.h"

enum class TransitionState { Blank, Anything };

struct AnimationContext {
    WINDOW *window;

    const std::string &word;

    const std::string &sourceDir;

    std::mt19937 &rng;

    inline void getDimensions(int &height, int &width) const {
        getmaxyx(window, height, width);
    }

    inline size_t wordLen() const {
        return word.size();
    }
};

class Animation {
   public:
    Animation(TransitionState startState, TransitionState endState)
        : startState(startState), endState(endState) {
    }

    virtual ~Animation() = default;

    void run(const AnimationContext &context);

    virtual const char *name() const = 0;

    const TransitionState startState;
    const TransitionState endState;

   protected:
    virtual void drawFrame(const AnimationContext &context) = 0;
};
