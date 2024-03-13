--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE 2024.03.12 14:52:05
--

---@type MainUI_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end

--function M:PreConstruct(IsDesignTime)
--end

local imgBgs = {}
imgBgs[1] = '/Game/111.111'
imgBgs[2] = '/Game/222.222'
local indexImg = 1

function M:Construct()
    self.btnLoad.OnClicked:Add(self, M.OnClickLoad)
    self.btnRelease.OnClicked:Add(self, M.OnClickRelease)
    self.btnClose.OnClicked:Add(self, M.OnClickClose)
end

function M:OnClickLoad()
    indexImg = indexImg + 1
    if indexImg > #imgBgs then
        indexImg = 1
    end
    self.imgBg:SetImageName(imgBgs[indexImg])
end

function M:OnClickRelease()
    self.imgBg:SetImageName("")
end

function M:OnClickClose()
    self:RemoveFromParent()
end

return M
