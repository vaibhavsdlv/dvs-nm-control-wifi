#include <wificontrol.h>
#include <gtest/gtest.h>

#include <memory>

namespace test_wifi_control {

using namespace testing;

class TestWifiControl : public Test
{
public:
    TestWifiControl()
        : wifiControl()
    {
    }

    std::unique_ptr< ABC::WifiControl > wifiControl;
};

TEST_F(TestWifiControl, DISABLED_GetAllAccessPoints_NOWIFI)
{
    std::vector<std::string> list;

    EXPECT_ANY_THROW( list = wifiControl->GetAllAccessPoints() );
}

TEST_F(TestWifiControl, GetAllAccessPoints_WIFI)
{
    std::vector<std::string> list;

    EXPECT_NO_THROW( list = wifiControl->GetAllAccessPoints() );
    EXPECT_TRUE( 0 < list.size() );
}

} // namespace test_wifi_control
