#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Anim
    @ingroup Anim
    @brief animation system facade
*/
#include "Anim/AnimTypes.h"
#include "Resource/ResourceLabel.h"
#include "Resource/Locator.h"
#include "Core/Time/Duration.h"

namespace Oryol {

class Anim {
public:
    /// setup the animation module
    static void Setup(const AnimSetup& setup);
    /// discard the animation module
    static void Discard();
    /// check if animation module is setup
    static bool IsValid();
    /// get the original AnimSetup object
    static const struct AnimSetup& AnimSetup();
    /// evaluate all active animations
    static void Update(float frameDurationInSeconds);

    /// generate new resource label and push on label stack
    static ResourceLabel PushLabel();
    /// push explicit resource label on label stack
    static void PushLabel(ResourceLabel label);
    /// pop resource label from label stack
    static ResourceLabel PopLabel();

    /// create an anim resource object
    template<class SETUP> static Id Create(const SETUP& setup);
    /// lookup an resource id by name 
    static Id Lookup(const Locator& name);
    /// destroy one or several anim resources by label
    static void Destroy(ResourceLabel label);

    /// access an animation library
    static const AnimLibrary& Library(const Id& libId);
    /// lookup a clip index by name
    static int ClipIndex(const Id& libId, const StringAtom& clipName);

    /// enable an animation instance
    static void EnableInstance(const Id& instId);
    /// disable an animation instance (don't evaluate during Update)
    static void DisableInstance(const Id& instId);
    /// return true if an animation instance is enabled
    static bool IsInstanceEnabed(const Id& instId);
    
    /// enqueue an animation job, return job id
    static AnimJobId Play(const Id& instId, const AnimJob& job);
    /// stop a specific animation job
    static void Stop(const Id& instId, AnimJobId jobId, bool allowFadeOut);
    /// stop all jobs on a mixing track
    static void StopTrack(const Id& instId, int trackIndex, bool allowFadeOut);
    /// stop all jobs
    static void StopAll(const Id& instId, bool allowFadeOut);
};

} // namespace Oryol

