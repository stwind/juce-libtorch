juce_add_console_app(main
    PRODUCT_NAME "Juce Libtorch")
target_sources(main PRIVATE main.cpp)
target_compile_definitions(main
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0)
target_link_libraries(main
        PRIVATE
            juce::juce_core
        PUBLIC
            juce::juce_recommended_config_flags
            juce::juce_recommended_warning_flags)
    
target_link_libraries(main PRIVATE ${TORCH_LIBRARIES})
