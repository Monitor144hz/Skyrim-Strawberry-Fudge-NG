#include "hook.h"
#include "../extern/OstimNG-API-Scene.h"
namespace StrawberryFudge
{
    bool Hook::UpdateDialogue(Actor *a_actor, DialogueResponse *a_response, bool a_unused)
    {
        
        if (!a_actor || !a_response) return  _UpdateDialogue(a_actor, a_response, a_unused); 


        
        auto* dialogueMenu = MenuTopicManager::GetSingleton(); 


        if (auto* topicInfo = dialogueMenu->currentTopicInfo)
        {
            auto responseData = topicInfo->GetDialogueData(a_actor); 
            auto* parentTopic = topicInfo->parentTopic; 
            if (TopicInfoSolutions.contains(topicInfo))
            {
                 TopicInfoSolutions[topicInfo]->Run(); 
            }
            else if (TopicSolutions.contains(parentTopic))
            {
                TopicSolutions[parentTopic]->Run(); 
            }
            SKSE::log::info("Topic Info: {:X} with Parent Topic {:X} and text {}", topicInfo->GetFormID(), parentTopic->GetFormID(), parentTopic->GetFullName());
        }
        


        return _UpdateDialogue(a_actor, a_response, a_unused); 
    }

    bool Hook::ConstructResponse(uint64_t unk01, char *a_filePath, BGSVoiceType *a_voiceType, TESTopic *a_topic, TESTopicInfo *a_topicInfo)
    {
        SKSE::log::info("Path: {}", a_filePath);
        char* charPtr = const_cast<char*>(piss.c_str());
        a_filePath = charPtr; 

        
        return _ConstructResponse(unk01, a_filePath, a_voiceType, a_topic, a_topicInfo); 
    }

    bool Hook::GetVoiceFilePath(uint64_t unk01, char *a_outPath, char *a_dataPath, char *a_pluginName, char *a_voiceName, char *a_fileName, char *a_extension)
    {
        // char* charPtr = const_cast<char*>(piss.c_str());

        // SKSE::log::info("Path: {}\\{}\\{}\\{}.{}", a_dataPath, a_pluginName, a_voiceName, a_fileName,a_extension);
        // return _GetVoiceFilePath(unk01, a_outPath, a_dataPath, charPtr, a_voiceName, a_fileName,  a_extension); 
        return true;
    }
}