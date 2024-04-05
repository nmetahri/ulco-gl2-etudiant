#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    Net net;

    hv::WebSocketService ws;
    ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        net.add(channel);
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
        if (net.isPending(channel)){
            if (!net.giveName(channel, msg)) {
                channel->send("Username already exists !");
            };
        } else {
            const auto name = net.findName(channel);
            std::string final_message = "[" + name.value() + "] " + msg;
            auto sendInput = [&final_message](const WebSocketChannelPtr& channel) {
                channel->send(final_message);
            };
            net.map(sendInput);
        }
    };
    ws.onclose = [&net](const WebSocketChannelPtr& channel) {
        net.del(channel);
        std::cout << "client disconnected" << std::endl;
    };

    hv::WebSocketServer server;
    server.registerWebSocketService(&ws);
    server.setPort(9000);
    std::cout << "waiting for clients..." << std::endl;
    server.run();

    return 0;
}

