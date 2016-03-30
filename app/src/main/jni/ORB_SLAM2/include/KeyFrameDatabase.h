/** Project: ORB-SLAM-Android.
 *  For more information see <https://github.com/castoryan/ORB-SLAM-Android>
 *
 *  The original work was done by Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
 *  For more information see <https://github.com/raulmur/ORB_SLAM2>
 *
 *  filename: KeyFrameDatabase.h
 *
 *  Created or Edited by Qinrui Yan on 30/Oct/2016.
 *  E-mail: castoryan1991@gmail.com
 *  Copyright © 2016 Qinrui Yan. All rights reserved.
 */

#ifndef KEYFRAMEDATABASE_H
#define KEYFRAMEDATABASE_H

#include <vector>
#include <list>
#include <set>

#include "KeyFrame.h"
#include "Frame.h"
#include "ORBVocabulary.h"

#include<mutex>


namespace ORB_SLAM2
{

class KeyFrame;
class Frame;


class KeyFrameDatabase
{
public:

    KeyFrameDatabase(const ORBVocabulary &voc);

   void add(KeyFrame* pKF);

   void erase(KeyFrame* pKF);

   void clear();

   // Loop Detection
   std::vector<KeyFrame *> DetectLoopCandidates(KeyFrame* pKF, float minScore);

   // Relocalization
   std::vector<KeyFrame*> DetectRelocalizationCandidates(Frame* F);

protected:

  // Associated vocabulary
  const ORBVocabulary* mpVoc;

  // Inverted file
  std::vector<list<KeyFrame*> > mvInvertedFile;

  // Mutex
  std::mutex mMutex;
};

} //namespace ORB_SLAM

#endif
