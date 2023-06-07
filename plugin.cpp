#include "pluginmodel.h"
#include <boost/dll/alias.hpp>

class ExamplePlugin:dingbot_plugin_model
{
private:
    boost::shared_ptr<dingbot::apimodel::Model> api;
public:
    ExamplePlugin()
    {
        // 插件初始化，注意，此处api实例未完成初始化！
    }
    void setApiModel(boost::shared_ptr<dingbot::apimodel::Model> _api) override
    {
        api = _api;
        api->log_debug("插件加载完成！");
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

    // 私聊消息事件
    // 字段: message:收到的消息内容，sender_id:发送人的QQ号
    void event_private_msg(std::string message, std::string sender_id) override
    {
        if(message == "你好")
        {
            api->log_debug("rec 你好");
        }
    }

    static boost::shared_ptr<ExamplePlugin> create_plugin()
    {
        return boost::shared_ptr<ExamplePlugin>(new ExamplePlugin);
    }
};

BOOST_DLL_ALIAS(ExamplePlugin::create_plugin,create_plugin)