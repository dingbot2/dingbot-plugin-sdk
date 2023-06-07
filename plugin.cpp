#include "pluginmodel.h"
#include <boost/dll/alias.hpp>

class ExamplePlugin:dingbot_plugin_model
{
private:
    boost::shared_ptr<dingbot::apimodel::Model> api;
public:
    ExamplePlugin()
    {
        // 插件初始化
    }
    void setApiModel(boost::shared_ptr<dingbot::apimodel::Model> _api) override
    {
        api = _api;
    }
    dingbot_plugin_info getPluginInfo() const override
    {
        dingbot_plugin_info info;
        info.name = "example";
        info.author = "dinglz";
        info.pluginName = "示例插件";
        info.description = "用来演示插件的编写";
        return info;
    }

    static boost::shared_ptr<ExamplePlugin> create_plugin()
    {
        return boost::shared_ptr<ExamplePlugin>(new ExamplePlugin);
    }
};

BOOST_DLL_ALIAS(ExamplePlugin::create_plugin,create_plugin)