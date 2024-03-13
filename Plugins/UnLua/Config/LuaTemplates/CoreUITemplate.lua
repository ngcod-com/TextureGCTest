--
-- DESCRIPTION
--
-- @ShenZhen EOneGame Co,Ltd.
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local TemplateName = Class()

function TemplateName:Initialize(Initializer)
	-- 下面代码必须存在，勿动. 防止UObject对应的Lua对象被默认垃圾回收
	-- 释放的地方在CoreUI
	RegisterGlobalLua(self)
end

-- 每次被添加到Viewport或是ParentUI被添加到Viewport都会调用
-- 通常处理EvtMgr事件监听，控件事件监听，定时器初始化
function TemplateName:OnAddToScreen()
end

-- 每次从在Viewport改为不在Viewport中都会调用
-- 通常处理EvtMgr事件监听的取消，控件事件监听的取消，定时器清理
function TemplateName:OnRemoveFromStage()
end

--function TemplateName:PreConstruct(IsDesignTime)
--end

-- function TemplateName:Construct()
-- end

--function TemplateName:Tick(MyGeometry, InDeltaTime)
--end

return TemplateName